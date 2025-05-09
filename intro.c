#include "config.h"

void intro(GameState *currentState, Graphics objects, int *score)
{
	BeginDrawing();

		ClearBackground(BLACK);
		DrawTextureEx(objects.blueplanet.texture, objects.blueplanet.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.earth.texture, objects.earth.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.purpleplanet.texture, objects.purpleplanet.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.redplanet.texture, objects.redplanet.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.rocketwhite.texture, objects.rocketwhite.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.satellite.texture, objects.satellite.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.saturn.texture, objects.saturn.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.sun.texture, objects.sun.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.title.texture, objects.title.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whiteshootingstar.texture, objects.whiteshootingstar.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whitestar.texture, objects.whitestar.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whitestars1.texture, objects.whitestars1.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.whitestars2.texture, objects.whitestars2.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.yellowhalfmoon.texture, objects.yellowhalfmoon.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.yellowshootingstar.texture, objects.yellowshootingstar.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		DrawTextureEx(objects.yellowstars.texture, objects.yellowstars.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
		
		
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
