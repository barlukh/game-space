#include "config.h"

void intro(GameState *currentState, Visuals space, int *score)
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
		DrawTexture(space.text, 1120, 1350, WHITE);
		DrawTexture(space.whiteshootingstar, 1000, 300, WHITE);
		DrawTexture(space.whitestar, 3500, 700, WHITE);
		DrawTexture(space.whitestars1, 3000, 400, WHITE);
		DrawTexture(space.whitestars2, 200, 1100, WHITE);
		DrawTexture(space.yellowhalfmoon, 100, 100, WHITE);
		DrawTexture(space.yellowshootingstar, 300, 150, WHITE);
		DrawTexture(space.yellowstars, 3650, 100, WHITE);
		
		
		int text1Width = MeasureText(TextFormat("Score: %d", *score), 100);
		int text2Width = MeasureText("W, S, A, D to move. Arrows to change bullets' direction.", 50);
		int text3Width = MeasureText("Press SPACE to start!", 50);
		int offset = 400;

		DrawText(TextFormat("Score: %d", *score), SCREEN_WIDTH / 2 - text1Width / 2, SCREEN_HEIGHT-offset+100, 100, WHITE);
		DrawText("W, S, A, D to move. Arrows to change bullets' direction.", SCREEN_WIDTH / 2 - text2Width / 2, SCREEN_HEIGHT -offset, 50, ORANGE);
		DrawText("Press SPACE to start!", SCREEN_WIDTH / 2 - text3Width / 2, SCREEN_HEIGHT-offset-100, 50, ORANGE);

	EndDrawing();

	if (IsKeyPressed(KEY_SPACE))
	{
		*currentState = GAMEPLAY;
		*score = 0;
	}
}
