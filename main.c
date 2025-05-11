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


	// Main loop

	while (!WindowShouldClose())
	{
		switch (currentState)
		{
			case INTRO:
				intro(&currentState, &objects);
				break;

			case GAMEPLAY:
			{
				controls_player(&objects);
				objects_update(&objects);
				check_collisions(&currentState, &objects);

				BeginDrawing();

					objects_draw(&objects);

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
