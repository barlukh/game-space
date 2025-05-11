#include "config.h"

void intro(GameState *currentState, Graphics *objects)
{
	BeginDrawing();
		
		ClearBackground(BLACK);
		
		DrawTexture(objects->blueplanet.tex, objects->blueplanet.pos.x, objects->blueplanet.pos.y, WHITE);
		DrawTexture(objects->earth.tex, objects->earth.pos.x, objects->earth.pos.y, WHITE);
		DrawTexture(objects->purpleplanet.tex, objects->purpleplanet.pos.x, objects->purpleplanet.pos.y, WHITE);
		DrawTexture(objects->redplanet.tex, objects->redplanet.pos.x, objects->redplanet.pos.y, WHITE);
		DrawTexture(objects->rocketwhite.tex, objects->rocketwhite.pos.x, objects->rocketwhite.pos.y, WHITE);
		DrawTexture(objects->satellite.tex, objects->satellite.pos.x, objects->satellite.pos.y, WHITE);
		DrawTexture(objects->saturn.tex, objects->saturn.pos.x, objects->saturn.pos.y, WHITE);
		DrawTexture(objects->sun.tex, objects->sun.pos.x, objects->sun.pos.y, WHITE);
		DrawTexture(objects->title.tex, objects->title.pos.x, objects->title.pos.y, WHITE);
		DrawTexture(objects->whiteshootingstar.tex, objects->whiteshootingstar.pos.x, objects->whiteshootingstar.pos.y, WHITE);
		DrawTexture(objects->whitestar.tex, objects->whitestar.pos.x, objects->whitestar.pos.y, WHITE);
		DrawTexture(objects->whitestars1.tex, objects->whitestars1.pos.x, objects->whitestars1.pos.y, WHITE);
		DrawTexture(objects->whitestars2.tex, objects->whitestars2.pos.x, objects->whitestars2.pos.y, WHITE);
		DrawTexture(objects->yellowhalfmoon.tex, objects->yellowhalfmoon.pos.x, objects->yellowhalfmoon.pos.y, WHITE);
		DrawTexture(objects->yellowshootingstar.tex, objects->yellowshootingstar.pos.x, objects->yellowshootingstar.pos.y, WHITE);
		DrawTexture(objects->yellowstars.tex, objects->yellowstars.pos.x, objects->yellowstars.pos.y, WHITE);
	
	
		DrawText(TextFormat("Score: %d", score), (GetScreenWidth() / 2) - (MeasureText(TextFormat("Score: %d", score),
		100 * SCALE) / 2), (GetScreenHeight()) * (1700 / 2160.0f), 100 * SCALE, WHITE);
		
		DrawText(TextFormat("W, S, A, D to move. Arrow keys to shoot."), (GetScreenWidth() / 2) - (MeasureText(TextFormat("W, S, A, D to move. Arrow keys to shoot."),
		50 * SCALE) / 2), (GetScreenHeight()) * (1950 / 2160.0f), 50 * SCALE, ORANGE);
		
		DrawText(TextFormat("Press SPACE to start!"), (GetScreenWidth() / 2) - (MeasureText(TextFormat("Press SPACE to start!"),
		50 * SCALE) / 2), (GetScreenHeight()) * (2050 / 2160.0f), 50 * SCALE, ORANGE);

	EndDrawing();

	if (IsKeyPressed(KEY_SPACE))
	{
		*currentState = GAMEPLAY;
		score = 0;
	}
}
