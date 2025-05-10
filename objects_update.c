#include "config.h"

void objects_update(Graphics *objects)
{
	// Timer

	timer.elapsedFrame += GetFrameTime();
	timer.elapsedSpawn += GetFrameTime();
	if (timer.elapsedFrame >= FRAME_THRESHOLD) {
		timer.frame = (timer.frame + 1) % TOTAL_FRAMES;
		timer.elapsedFrame = 0.0f;
	}
	
	if (timer.spawn < ENEMY_MAX) {
		if (timer.elapsedSpawn >= SPAWN_THRESHOLD) {
			timer.spawn++;
			timer.elapsedSpawn = 0.0f;
		}
	}
	
	
	
	for (int i = 0; i < spawn.count; i++) {
		enemies[i].enemyDir.x = objects.player.pos.x - enemies[i].enemyPos.x;
		enemies[i].enemyDir.y = objects.player.pos.y - enemies[i].enemyPos.y;

		float length = sqrtf(enemies[i].enemyDir.x * enemies[i].enemyDir.x + enemies[i].enemyDir.y * enemies[i].enemyDir.y);
		if (length != 0) {
			enemies[i].enemyDir.x /= length;
			enemies[i].enemyDir.y /= length;
		}
		
		enemies[i].enemyPos.x += enemies[i].enemyDir.x * ENEMY_SPEED;
		enemies[i].enemyPos.y += enemies[i].enemyDir.y * ENEMY_SPEED;

		enemies[i].enemyRec.x = enemies[i].enemyPos.x;
		enemies[i].enemyRec.y = enemies[i].enemyPos.y;
	}
	objects.player.rec.x = objects.player.pos.x;
	objects.player.rec.y = objects.player.pos.y;



	static double lastShotTime = 0;
	const double fireRate = 0.25;
	bulletDir = (Vector2){0, 0}; // Reset direction each frame

	// Check for movement input (directional shooting)
	if (IsKeyDown(KEY_W)) bulletDir.y = -1; // Up
	if (IsKeyDown(KEY_S)) bulletDir.y = 1;  // Down
	if (IsKeyDown(KEY_A)) bulletDir.x = -1; // Left
	if (IsKeyDown(KEY_D)) bulletDir.x = 1;  // Right

	// Normalize diagonal movement
	if (bulletDir.x != 0 && bulletDir.y != 0) {
		bulletDir.x *= 0.707f;
		bulletDir.y *= 0.707f;
	}

	// **Fire bullets only if a movement key is pressed**
	if ((bulletDir.x != 0 || bulletDir.y != 0) && GetTime() - lastShotTime >= fireRate) {
		for (int i = 0; i < BULLET_MAX; i++) {
			if (!bullets[i].active) {
				bullets[i].pos = (Vector2){playerPos.x + 20, playerPos.y + 10}; // Offset from player
				bullets[i].direction = bulletDir;  // Assign movement direction
				bullets[i].active = true;
				lastShotTime = GetTime();  // Reset cooldown timer
				break;
			}
		}
	}

	// Move active bullets
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i].active) {
			bullets[i].pos.x += bullets[i].direction.x * BULLET_SPEED * GetFrameTime();
			bullets[i].pos.y += bullets[i].direction.y * BULLET_SPEED * GetFrameTime();
		}
	}
}
