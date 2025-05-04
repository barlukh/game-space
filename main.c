#include "config.h"

int main(void)
{
	SetTraceLogLevel(LOG_NONE);

	// Initial screen and game configuration
	GameState currentState = INTRO;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(SCREEN_FPS);
	SetWindowState(FLAG_FULLSCREEN_MODE);

	// Animation and time config
	FrameCounter time = {0, 0.2f, 0.0f};
	SpawnCounter spawn = {0, 3.0f, 0.0f};

	// Space
	Visuals space = textures_load(space);

	// Player
	Texture2D playerTex[2] = {
		LoadTexture("graphics/astronaut1.png"),
		LoadTexture("graphics/astronaut2.png")
	};
	Vector2 playerPos = {SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0};
	Rectangle playerRec = {playerPos.x, playerPos.y, playerTex[0].width, playerTex[0].height};

	// Enemies
	Texture2D enemyTex = LoadTexture("graphics/ufo.png");
	Enemy enemies[MAX_ENEMIES];

	int randomPick;
	int randomSide[4][2];
	
	for (int i = 0; i < MAX_ENEMIES; i++) {
		randomPick = GetRandomValue(0, 3);
		randomizer(randomSide);
		enemies[i].enemyPos.x = randomSide[randomPick][0];
		enemies[i].enemyPos.y = randomSide[randomPick][1];
		enemies[i].enemyRec = (Rectangle){enemies[i].enemyPos.x, enemies[i].enemyPos.y, enemyTex.width, enemyTex.height};
		enemies[i].enemyDir = (Vector2){playerPos.x - enemies[i].enemyPos.x, playerPos.y - enemies[i].enemyPos.y};
	}

	// Bullets
	Bullet bullets[MAX_BULLETS] = {0};
	float bulletSpeed = 30.0f;
	int bulletTimer = 0;
	int fireRate = 5;
	Vector2 bulletDir = {1.0f, 0.0f};

	while (!WindowShouldClose())
	{
		switch (currentState)
		{
			case INTRO:
				intro(&currentState, space);
				break;

			case GAMEPLAY:
			{
				// Timers
				
				time.elapsed += GetFrameTime();
				if (time.elapsed >= time.threshold) {
					time.frame = (time.frame + 1) % 2;
					time.elapsed = 0.0f;
				}
				
				if (spawn.count < MAX_ENEMIES) {
					spawn.elapsed += GetFrameTime();
					if (spawn.elapsed >= spawn.threshold) {
						spawn.count++;
						spawn.elapsed = 0.0f;
					}
				}

				// Input controls
				controls_player(&playerPos, playerTex[0]);
				controls_bullets(&bulletDir);

				// Enemy movement updates
				for (int i = 0; i < spawn.count; i++) {
					enemies[i].enemyDir.x = playerPos.x - enemies[i].enemyPos.x;
					enemies[i].enemyDir.y = playerPos.y - enemies[i].enemyPos.y;

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

				playerRec.x = playerPos.x;
				playerRec.y = playerPos.y;

				// Bullet firing mechanism
				bulletTimer++;
				if (bulletTimer >= fireRate) {
					for (int i = 0; i < MAX_BULLETS; i++) {
						if (!bullets[i].active) {
							bullets[i].position = (Vector2){playerPos.x + playerTex[0].width, playerPos.y + playerTex[0].height / 2.0};
							bullets[i].direction = bulletDir;
							bullets[i].active = true;
							bulletTimer = 0;
							break;
						}
					}
				}

				// Bullet movement
				for (int i = 0; i < MAX_BULLETS; i++) {
					if (bullets[i].active) {
						bullets[i].position.x += bullets[i].direction.x * bulletSpeed;
						bullets[i].position.y += bullets[i].direction.y * bulletSpeed;
						if (bullets[i].position.x < 0 || bullets[i].position.x > SCREEN_WIDTH ||
							bullets[i].position.y < 0 || bullets[i].position.y > SCREEN_HEIGHT)
								bullets[i].active = false;
					}
				}

				// Drawing
				BeginDrawing();

					ClearBackground(BLACK);
					textures_draw(space, playerTex[time.frame], playerPos, enemyTex, enemies, spawn);

					for (int i = 0; i < MAX_BULLETS; i++) {
						if (bullets[i].active)
							DrawCircleV(bullets[i].position, 10, YELLOW);
					}

				EndDrawing();

				// Collision detection
				check_collisions(enemies, &playerPos, playerRec, randomPick, randomSide, &currentState, bullets, &spawn);
			} break;

			default:
				break;
		}
	}

	// Clean up resources after exiting the game loop
	textures_unload(space);
	for (int i = 0; i < 2; i++) {
		UnloadTexture(playerTex[i]);
	}
	UnloadTexture(enemyTex);
	CloseWindow();

	return 0;
}
