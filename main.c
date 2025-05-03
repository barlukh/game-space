#include "config.h"
#include <raylib.h>

#define MAX_BULLET 100
typedef struct Bullet {
	Vector2 position;
	Vector2 direction;
	bool active;
} Bullet;

// TODO: create rectangle collision for the astronaut
// firing bullets from astronaut
int main(void)
{
	SetTraceLogLevel(LOG_NONE);
	// Initial screen and game configuration
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(SCREEN_FPS);
	SetWindowState(FLAG_WINDOW_UNDECORATED);

	// Initial textures, vectors, and rectangles
	Texture2D sun = LoadTexture("graphics/sun.png");
	Texture2D earth = LoadTexture("graphics/earth.png");
	Texture2D rocket = LoadTexture("graphics/rocketwhite.png");
	Texture2D astronaut = LoadTexture("graphics/astronaut1.png");
	
	// initial for Sun
	Vector2 sunPos = {GetScreenWidth()/1.5f, GetScreenHeight()/1.5f};
	Vector2 sunSpeed = {9.0f, 4.0f};
	int sunRadius = 20;

	// initial for astronauts
	Vector2 astronautPos = {SCREEN_WIDTH/2.0, SCREEN_HEIGHT/2.0};
	int astronautSpeed = 20;

	// bullets
	Bullet bullets[MAX_BULLET] = {0};
	float bulletSpeed = 20.0f;
	int bulletTimer = 0;
	int fireRate = 5;
	Vector2 bulletDir = {1.0f, 0.0f};
	while (!WindowShouldClose())
	{
		sunPos.x += sunSpeed.x;
		sunPos.y += sunSpeed.y;
		if (sunPos.x <= 0 || sunPos.x + sun.width >= SCREEN_WIDTH)
			sunSpeed.x *= -1.0f;
		if (sunPos.y <=0 || sunPos.y + sun.height >= SCREEN_HEIGHT)
			sunSpeed.y *= -1.0f;
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
			DrawTexture(sun, sunPos.x, sunPos.y, WHITE);
			DrawTexture(earth, 1000, 300, WHITE);
			DrawTexture(rocket, 100, 200, WHITE);
			DrawTexture(astronaut, astronautPos.x, astronautPos.y, WHITE);

		for (int i = 0; i < MAX_BULLET; i++)
		{
			if (bullets[i].active)
				DrawCircleV(bullets[i].position, 10, YELLOW);
		}
		
		EndDrawing();
	}
	// Clean up resources after exiting the game loop
	UnloadTexture(sun);
	UnloadTexture(earth);
	UnloadTexture(rocket);
	UnloadTexture(astronaut);

	CloseWindow();

	return 0;
}
