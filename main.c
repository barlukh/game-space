#include "config.h"

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

	while (!WindowShouldClose())
	{
		BeginDrawing();
			
			ClearBackground(BLACK);
			DrawTexture(sun, 500, 600, WHITE);
			DrawTexture(earth, 1000, 300, WHITE);
			DrawTexture(rocket, 2000, 300, WHITE);
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