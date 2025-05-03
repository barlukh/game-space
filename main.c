#include "config.h"
#include <raylib.h>

// TODO: create rectangle collision for the astronaut
// and moving it around using asdw
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
	
	Vector2 sunPos = {GetScreenWidth()/1.5f, GetScreenHeight()/1.5f};
	Vector2 sunSpeed = {9.0f, 4.0f};
	int sunRadius = 20;
	while (!WindowShouldClose())
	{
		sunPos.x += sunSpeed.x;
		sunPos.y += sunSpeed.y;
		if (sunPos.x <= 0 || sunPos.x + sun.width >= SCREEN_WIDTH)
			sunSpeed.x *= -1.0f;
		if (sunPos.y <=0 || sunPos.y + sun.height >= SCREEN_HEIGHT)
			sunSpeed.y *= -1.0f;

		BeginDrawing();
			
			ClearBackground(BLACK);
			DrawTexture(sun, sunPos.x, sunPos.y, WHITE);
			DrawTexture(earth, 1000, 300, WHITE);
			DrawTexture(rocket, 100, 200, WHITE);
			DrawTexture(astronaut, 2000, 1300, WHITE);
		
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
