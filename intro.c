#include "config.h"

void intro(GameState *currentState, Visuals space)
{
	BeginDrawing();

		ClearBackground(BLACK);
		DrawTexture(space.blueplanet, 1500, 200, WHITE);
		DrawTexture(space.earth, 1792, 952, WHITE);
		DrawTexture(space.purpleplanet, 600, 1300, WHITE);
		DrawTexture(space.redplanet, 400, 500, WHITE);
		DrawTexture(space.rocketwhite, 100, 1900, WHITE);
		DrawTexture(space.satellite, 2050, 850, WHITE);
		DrawTexture(space.saturn, 800, 100, WHITE);
		DrawTexture(space.sun, 1000, 500, WHITE);
		DrawTexture(space.whiteshootingstar, 1000, 300, WHITE);
		DrawTexture(space.whitestar, 3500, 700, WHITE);
		DrawTexture(space.whitestars1, 3000, 400, WHITE);
		DrawTexture(space.whitestars2, 200, 1100, WHITE);
		DrawTexture(space.yellowhalfmoon, 100, 100, WHITE);
		DrawTexture(space.yellowshootingstar, 300, 150, WHITE);
		DrawTexture(space.yellowstars, 3650, 100, WHITE);
		
		int textWidth = MeasureText("Press ENTER to start!", 50);
		DrawText("Press ENTER to start!", SCREEN_WIDTH / 2 - textWidth / 2, 1300, 50, YELLOW);

	EndDrawing();

	if (IsKeyPressed(KEY_ENTER))
	{
		*currentState = GAMEPLAY;
	}
}
