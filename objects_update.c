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
	
	
	// Bullets
	
	static double lastShotTime = 0;
	float deltaTime = GetFrameTime();

	Vector2 bulletDir = {0, 0};
	if (IsKeyDown(KEY_UP)) bulletDir.y = -1;
	if (IsKeyDown(KEY_DOWN)) bulletDir.y = 1;
	if (IsKeyDown(KEY_LEFT)) bulletDir.x = -1;
	if (IsKeyDown(KEY_RIGHT)) bulletDir.x = 1;

	if (bulletDir.x != 0 && bulletDir.y != 0) {
		bulletDir.x *= 0.707f;
		bulletDir.y *= 0.707f;
	}

	if ((bulletDir.x != 0 || bulletDir.y != 0) && GetTime() - lastShotTime >= BULLET_RATE) {
		for (int i = 0; i < BULLET_MAX; i++) {
			if (!objects->bullet[i].active) {
				objects->bullet[i].pos = (Vector2){objects->player.pos.x + 20, objects->player.pos.y + 10};
				objects->bullet[i].dir = bulletDir;
				objects->bullet[i].active = true;
				lastShotTime = GetTime();
				break;
			}
		}
	}

	for (int i = 0; i < BULLET_MAX; i++) {
		if (objects->bullet[i].active) {
			objects->bullet[i].pos.x += objects->bullet[i].dir.x * BULLET_SPEED * SCALE * deltaTime;
			objects->bullet[i].pos.y += objects->bullet[i].dir.y * BULLET_SPEED * SCALE * deltaTime;

			if (objects->bullet[i].pos.x < 0 || objects->bullet[i].pos.x > SCREEN_WIDTH ||
				objects->bullet[i].pos.y < 0 || objects->bullet[i].pos.y > SCREEN_HEIGHT) {
				objects->bullet[i].active = false;
			}
		}
	}
	

	// Enemies


	for (int i = 0; i < timer.spawn; i++) {
		float dx = objects->player.pos.x - objects->enemy[i].pos.x;
		float dy = objects->player.pos.y - objects->enemy[i].pos.y;
	
		dx *= SCALE;
		dy *= SCALE;
	
		float length = sqrtf(dx * dx + dy * dy);
		if (length != 0) {
			dx /= length;
			dy /= length;
		}
	
		objects->enemy[i].pos.x += dx * ENEMY_SPEED * SCALE * deltaTime;
		objects->enemy[i].pos.y += dy * ENEMY_SPEED * SCALE * deltaTime;
	
		objects->enemy[i].rec.x = objects->enemy[i].pos.x;
		objects->enemy[i].rec.y = objects->enemy[i].pos.y;
	}


	// Player

	objects->player.rec.x = objects->player.pos.x;
	objects->player.rec.y = objects->player.pos.y;
}
