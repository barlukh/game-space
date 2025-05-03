#include "config.h"
#include <math.h>
#include <raylib.h>

int main(void)
{
	SetTraceLogLevel(LOG_NONE);
	
	// Initial screen and game configuration
	GameState currentState = INTRO;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(SCREEN_FPS);
	SetWindowState(FLAG_FULLSCREEN_MODE);

	// Initial textures, vectors, and rectangles
	Visuals visuals;
	visuals.blueplanet = LoadTexture("graphics/blueplanet.png");
	visuals.earth = LoadTexture("graphics/earth.png");
	visuals.fullmoon = LoadTexture("graphics/fullmoon.png");
	visuals.hurricane = LoadTexture("graphics/hurricane.png");
	visuals.purpleplanet = LoadTexture("graphics/purpleplanet.png");
	visuals.redmoon = LoadTexture("graphics/redmoon.png");
	visuals.redplanet = LoadTexture("graphics/redplanet.png");
	visuals.rocketwhite = LoadTexture("graphics/rocketwhite.png");
	visuals.satellite = LoadTexture("graphics/satellite.png");
	visuals.saturn = LoadTexture("graphics/saturn.png");
	visuals.sun = LoadTexture("graphics/sun.png");
	visuals.whitemoon = LoadTexture("graphics/whitemoon.png");
	visuals.whiteshootingstar = LoadTexture("graphics/whiteshootingstar.png");
	visuals.whitestar = LoadTexture("graphics/whitestar.png");
	visuals.whitestars1 = LoadTexture("graphics/whitestars1.png");
	visuals.whitestars2 = LoadTexture("graphics/whitestars2.png");
	visuals.yellowhalfmoon = LoadTexture("graphics/yellowhalfmoon.png");
	visuals.yellowshootingstar = LoadTexture("graphics/yellowshootingstar.png");
	visuals.yellowstar = LoadTexture("graphics/yellowstar.png");
	visuals.yellowstars1 = LoadTexture("graphics/yellowstars1.png");
	visuals.yellowstars2 = LoadTexture("graphics/yellowstars2.png");
	
	Texture2D astronaut = LoadTexture("graphics/astronaut1.png");

	// initial for astronauts
	Vector2 astronautPos = {SCREEN_WIDTH/2.0, SCREEN_HEIGHT/2.0};
	int astronautSpeed = 20;

	// bullets
	Bullet bullets[MAX_BULLET] = {0};
	float bulletSpeed = 30.0f;
	int bulletTimer = 0;
	int fireRate = 5;
	Vector2 bulletDir = {1.0f, 0.0f};

	// enemy
	Vector2 enemyPos = {100, 100};
	float enemySpeed = 10.0f;

	Rectangle enemyRec = {enemyPos.x, enemyPos.y, visuals.purpleplanet.width, visuals.purpleplanet.height};
	Rectangle astronautRec = {astronautPos.x, astronautPos.y, astronaut.width, astronaut.height};

	while (!WindowShouldClose())
	{
		switch (currentState)
		{
			case INTRO:
				intro(&currentState, visuals);
			break;

			case GAMEPLAY:
			{
				if (IsKeyDown(KEY_A))
					astronautPos.x -= astronautSpeed;
				if (IsKeyDown(KEY_S))
					astronautPos.y += astronautSpeed;
				if (IsKeyDown(KEY_D))
					astronautPos.x += astronautSpeed;
				if (IsKeyDown(KEY_W))
					astronautPos.y -= astronautSpeed;

				if (astronautPos.x <= 0)
					astronautPos.x = 0;
				if (astronautPos.x > SCREEN_WIDTH - astronaut.width)
					astronautPos.x = SCREEN_WIDTH - astronaut.width;
				if (astronautPos.y <= 0)
					astronautPos.y = 0;
				if (astronautPos.y > SCREEN_HEIGHT - astronaut.height)
					astronautPos.y = SCREEN_HEIGHT - astronaut.height;

				if (IsKeyDown(KEY_RIGHT))
					bulletDir = (Vector2){1.0f, 0.0f};
				if (IsKeyDown(KEY_LEFT))
					bulletDir = (Vector2){-1.0f, 0.0f};
				if (IsKeyDown(KEY_UP))
					bulletDir = (Vector2){0.0f, -1.0f};
				if (IsKeyDown(KEY_DOWN))
					bulletDir = (Vector2){0.0f, 1.0f};
				if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP))
					bulletDir = (Vector2){1.0f, -1.0f};
				if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN))
					bulletDir = (Vector2){1.0f, 1.0f};
				if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN))
					bulletDir = (Vector2){-1.0f, 1.0f};
				if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP))
					bulletDir = (Vector2){-1.0f, -1.0f};

				Vector2 direction = { astronautPos.x - enemyPos.x, astronautPos.y - enemyPos.y };
				float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
				if (length != 0)
				{
					direction.x /= length;
					direction.y /= length;
				}
				enemyPos.x += direction.x * enemySpeed;
				enemyPos.y += direction.y * enemySpeed;

				enemyRec.x = enemyPos.x;
				enemyRec.y = enemyPos.y;

				astronautRec.x = astronautPos.x;
				astronautRec.y = astronautPos.y;

				if (CheckCollisionRecs(enemyRec, astronautRec))
				{
					currentState = INTRO;
					break ;
				}
				bulletTimer++;
				if(bulletTimer >= fireRate)
				{
					for (int i = 0; i < MAX_BULLET; i++)
					{
						if (!bullets[i].active)
						{
							bullets[i].position = (Vector2){astronautPos.x + astronaut.width, astronautPos.y + astronaut.height/2.0};
							bullets[i].direction = bulletDir;
							bullets[i].active = true;
							bulletTimer = 0;
							break;
						}
					}
				}
				for (int i = 0; i < MAX_BULLET; i++)
				{
					if (bullets[i].active)
					{
						bullets[i].position.x += bullets[i].direction.x * bulletSpeed;
						bullets[i].position.y += bullets[i].direction.y * bulletSpeed;
						if (bullets[i].position.x < 0 || bullets[i].position.x > SCREEN_WIDTH || bullets[i].position.y < 0 || bullets[i].position.y > SCREEN_HEIGHT)
							bullets[i].active = false;
					}
				}
					BeginDrawing();
						
						ClearBackground(BLACK);

						DrawTexture(visuals.rocketwhite, 100, 1900, WHITE);
						DrawTexture(visuals.whiteshootingstar, 1000, 300, WHITE);
						DrawTexture(visuals.whitestar, 3500, 700, WHITE);
						DrawTexture(visuals.whitestars1, 3000, 400, WHITE);
						DrawTexture(visuals.whitestars2, 200, 1100, WHITE);
						DrawTexture(visuals.yellowhalfmoon, 100, 100, WHITE);
						DrawTexture(visuals.yellowshootingstar, 300, 150, WHITE);
						DrawTexture(visuals.yellowstars1, 3650, 100, WHITE);
						
						DrawTexture(astronaut, astronautPos.x, astronautPos.y, WHITE);
						DrawTexture(visuals.purpleplanet, enemyPos.x, enemyPos.y, WHITE);
						for (int i = 0; i < MAX_BULLET; i++)
						{
							if (bullets[i].active)
								DrawCircleV(bullets[i].position, 10, YELLOW);
						}
					
					EndDrawing();
					} break;
					default: break;
		}
	}

	// Clean up resources after exiting the game loop
	UnloadTexture(visuals.blueplanet);
	UnloadTexture(visuals.earth);
	UnloadTexture(visuals.fullmoon);
	UnloadTexture(visuals.hurricane);
	UnloadTexture(visuals.purpleplanet);
	UnloadTexture(visuals.redmoon);
	UnloadTexture(visuals.redplanet);
	UnloadTexture(visuals.rocketwhite);
	UnloadTexture(visuals.satellite);
	UnloadTexture(visuals.saturn);
	UnloadTexture(visuals.sun);
	UnloadTexture(visuals.whitemoon);
	UnloadTexture(visuals.whiteshootingstar);
	UnloadTexture(visuals.whitestar);
	UnloadTexture(visuals.whitestars1);
	UnloadTexture(visuals.whitestars2);
	UnloadTexture(visuals.yellowhalfmoon);
	UnloadTexture(visuals.yellowshootingstar);
	UnloadTexture(visuals.yellowstar);
	UnloadTexture(visuals.yellowstars1);
	UnloadTexture(visuals.yellowstars2);

	UnloadTexture(astronaut);

	CloseWindow();

	return 0;
}
