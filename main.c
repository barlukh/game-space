#include "config.h"

// Global variables

int score = 0;
int randomSidePick = 0;
int randomSpawnPos[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

Time timer = {0, 0, 0.0f, 0.0f};


int main(void)
{
	// Screen and log configuration
	
	SetTraceLogLevel(LOG_NONE);
	GameState currentState = INTRO;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(SCREEN_FPS);
	SetWindowState(FLAG_FULLSCREEN_MODE);
	DisableCursor();


	// Initialize objects

	Graphics objects;
	objects_load(&objects);


	// Bullets

	BulletObject bullets[BULLET_MAX] = {0};
	int bulletTimer = 0;
	int fireRate = 5;
	Vector2 bulletDir = {1.0f, 0.0f};


	while (!WindowShouldClose())
	{
		switch (currentState)
		{
			case INTRO:
				intro(&currentState, objects, &score);
				break;

			case GAMEPLAY:
			{
				// Input controls

				controls_player(&objects);
				controls_bullets(&bulletDir);

				// Enemy movement updates


				objects_update(*objects);
				
				// Collision detection
				check_collisions(enemies, &playerPos, playerRec, randomSidePick, randomSpawnPos, &currentState, bullets, &spawn, &score, objects);
				
				// Drawing
				BeginDrawing();
				
					ClearBackground(BLACK);
					objects_draw(objects, playerTex[timer.frame], playerPos, enemyTex, enemies, spawn, &score);


					for (int i = 0; i < BULLET_MAX; i++) {
						if (bullets[i].active)
							DrawCircleV(bullets[i].pos, 10, YELLOW);
					}

				EndDrawing();

			} break;

			default:
				break;
		}
	}

	// Clean up resources after exiting the game loop
	
	objects_unload(&objects);
	

	CloseWindow();

	return 0;
}
