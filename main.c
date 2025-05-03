#include "config.h"

int main(void)
{
	SetTraceLogLevel(LOG_NONE);

	// Initial screen and game configuration
	GameState currentState = INTRO;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(SCREEN_FPS);
	SetWindowState(FLAG_WINDOW_UNDECORATED);

	// Initial textures, vectors, and rectangles
	Visuals visuals;
	visuals.blueplanet = LoadTexture("graphics/blueplanet.png");
	visuals.earth = LoadTexture("graphics/earth.png");
	visuals.fullmoon = LoadTexture("graphics/fullmoon.png");
	visuals.hurricane = LoadTexture("graphics/hurricane.png");
	visuals.purpleplanet = LoadTexture("graphics/purpleplanet.png");
	visuals.redmoon = LoadTexture("graphics/redmoon.png");
	visuals.redplanet = LoadTexture("graphics/redplanet.png");
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
	
	
	Texture2D rocket = LoadTexture("graphics/rocketwhite.png");
	Texture2D astronaut = LoadTexture("graphics/astronaut1.png");

	while (!WindowShouldClose())
	{
		switch (currentState)
		{
			case INTRO:
				intro(&currentState, visuals);
			break;

			case GAMEPLAY:
			{
				BeginDrawing();
					
					ClearBackground(BLACK);
					DrawTexture(visuals.blueplanet, 1500, 200, WHITE);
					DrawTexture(visuals.earth, 1792, 952, WHITE);
					DrawTexture(visuals.purpleplanet, 600, 1300, WHITE);
					DrawTexture(visuals.redplanet, 400, 500, WHITE);
					DrawTexture(visuals.satellite, 2050, 850, WHITE);
					DrawTexture(visuals.saturn, 800, 100, WHITE);
					DrawTexture(visuals.sun, 1000, 500, WHITE);
					DrawTexture(visuals.whiteshootingstar, 1000, 300, WHITE);
					DrawTexture(visuals.whitestar, 3500, 700, WHITE);
					DrawTexture(visuals.whitestars1, 3000, 400, WHITE);
					DrawTexture(visuals.whitestars2, 200, 1100, WHITE);
					DrawTexture(visuals.yellowhalfmoon, 100, 100, WHITE);
					DrawTexture(visuals.yellowshootingstar, 300, 150, WHITE);
					DrawTexture(visuals.yellowstars1, 3650, 100, WHITE);
				
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

	UnloadTexture(rocket);
	UnloadTexture(astronaut);

	CloseWindow();

	return 0;
}
