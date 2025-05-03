#include "config.h"

int main(void)
{
	SetTraceLogLevel(LOG_NONE);
	
	// Initial screen and game configuration
	GameState currentState = INTRO;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(SCREEN_FPS);
	SetWindowState(FLAG_FULLSCREEN_MODE);

	// Space
	Visuals space = textures_load(space);

	// Player
	Texture2D player = LoadTexture("graphics/astronaut1.png");
	Vector2 playerPos = {SCREEN_WIDTH/2.0, SCREEN_HEIGHT/2.0};

	// Enemy
	int randomSide[4][2];
	randomSide[0][0] = GetRandomValue(0, SCREEN_WIDTH);
	randomSide[0][1] = -150;
	randomSide[1][0] = GetRandomValue(0, SCREEN_WIDTH);
	randomSide[1][1] = SCREEN_HEIGHT + 150;
	randomSide[2][0] = -150;
	randomSide[2][1] = GetRandomValue(0, SCREEN_HEIGHT);
	randomSide[3][0] = SCREEN_WIDTH + 150;
	randomSide[3][1] = GetRandomValue(0, SCREEN_HEIGHT);
	
	int randomPick = GetRandomValue(0, 3);
	Vector2 enemyPos = {randomSide[randomPick][0], randomSide[randomPick][1]};


	// Bullets
	Bullet bullets[MAX_BULLET] = {0};
	float bulletSpeed = 30.0f;
	int bulletTimer = 0;
	int fireRate = 5;
	Vector2 bulletDir = {1.0f, 0.0f};

	// Rectangles
	Rectangle playerRec = {playerPos.x, playerPos.y, player.width, player.height};
	Rectangle enemyRec = {enemyPos.x, enemyPos.y, space.ufo.width, space.ufo.height};

	while (!WindowShouldClose())
	{
		switch (currentState)
		{
			case INTRO:
				intro(&currentState, space);
			break;

			case GAMEPLAY:
			{
				controls_player(&playerPos, &player);
				controls_bullets(&bulletDir);

				Vector2 direction = { playerPos.x - enemyPos.x, playerPos.y - enemyPos.y };
				float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
				if (length != 0)
				{
					direction.x /= length;
					direction.y /= length;
				}
				enemyPos.x += direction.x * ENEMY_SPEED;
				enemyPos.y += direction.y * ENEMY_SPEED;

				enemyRec.x = enemyPos.x;
				enemyRec.y = enemyPos.y;

				playerRec.x = playerPos.x;
				playerRec.y = playerPos.y;

				
				bulletTimer++;
				if(bulletTimer >= fireRate)
				{
					for (int i = 0; i < MAX_BULLET; i++)
					{
						if (!bullets[i].active)
						{
							bullets[i].position = (Vector2){playerPos.x + player.width, playerPos.y + player.height/2.0};
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

						textures_draw(space);
						
						DrawTexture(player, playerPos.x, playerPos.y, WHITE);
						DrawTexture(space.ufo, enemyPos.x, enemyPos.y, WHITE);
						for (int i = 0; i < MAX_BULLET; i++)
						{
							if (bullets[i].active)
								DrawCircleV(bullets[i].position, 10, YELLOW);
						}
					
					EndDrawing();
				if (CheckCollisionRecs(enemyRec, playerRec))
				{
					playerPos.x = SCREEN_WIDTH/2.0;
					playerPos.y = SCREEN_HEIGHT/2.0;
					randomPick = GetRandomValue(0, 3);
					enemyPos.x = randomSide[randomPick][0];
					enemyPos.y = randomSide[randomPick][1];
					currentState = INTRO;
				}
				} break;
					default: break;
		}
	}

	// Clean up resources after exiting the game loop
	textures_unload(space);

	UnloadTexture(player);

	CloseWindow();

	return 0;
}
