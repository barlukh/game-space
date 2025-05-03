#include "config.h"

void intro(GameState *currentState, Visuals visuals)
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
		
		int textWidth = MeasureText("Press ENTER to start!", 50);
		DrawText("Press ENTER to start!", SCREEN_WIDTH / 2 - textWidth / 2, 1300, 50, YELLOW);

	EndDrawing();

	if (IsKeyPressed(KEY_ENTER))
		*currentState = GAMEPLAY;
}