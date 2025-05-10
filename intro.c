#include "config.h"

void intro(GameState *currentState, Graphics objects, int *score)
{
	BeginDrawing();

		ClearBackground(BLACK);
		DrawTextureEx(objects.blueplanet.tex, objects.blueplanet.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.earth.tex, objects.earth.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.purpleplanet.tex, objects.purpleplanet.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.redplanet.tex, objects.redplanet.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.rocketwhite.tex, objects.rocketwhite.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.satellite.tex, objects.satellite.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.saturn.tex, objects.saturn.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.sun.tex, objects.sun.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.title.tex, objects.title.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whiteshootingstar.tex, objects.whiteshootingstar.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whitestar.tex, objects.whitestar.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whitestars1.tex, objects.whitestars1.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whitestars2.tex, objects.whitestars2.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.yellowhalfmoon.tex, objects.yellowhalfmoon.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.yellowshootingstar.tex, objects.yellowshootingstar.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.yellowstars.tex, objects.yellowstars.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		
		
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
