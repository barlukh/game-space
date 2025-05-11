#include "config.h"

void objects_draw(Graphics *objects)
{
	ClearBackground(BLACK);

	// Static objects

	DrawTexture(objects->rocketwhite.tex, objects->rocketwhite.pos.x, objects->rocketwhite.pos.y, WHITE);
	DrawTexture(objects->whiteshootingstar.tex, objects->whiteshootingstar.pos.x, objects->whiteshootingstar.pos.y, WHITE);
	DrawTexture(objects->whitestar.tex, objects->whitestar.pos.x, objects->whitestar.pos.y, WHITE);
	DrawTexture(objects->whitestars1.tex, objects->whitestars1.pos.x, objects->whitestars1.pos.y, WHITE);
	DrawTexture(objects->whitestars2.tex, objects->whitestars2.pos.x, objects->whitestars2.pos.y, WHITE);
	DrawTexture(objects->yellowhalfmoon.tex, objects->yellowhalfmoon.pos.x, objects->yellowhalfmoon.pos.y, WHITE);
	DrawTexture(objects->yellowshootingstar.tex, objects->yellowshootingstar.pos.x, objects->yellowshootingstar.pos.y, WHITE);
	DrawTexture(objects->yellowstars.tex, objects->yellowstars.pos.x, objects->yellowstars.pos.y, WHITE);
	DrawText(TextFormat("Score: %d", score), 10, SCREEN_HEIGHT - (100 * SCALE), 100 * SCALE, WHITE);
	

	// Player

	DrawTexture(objects->player.tex[timer.frame], objects->player.pos.x, objects->player.pos.y, WHITE);


	// Enemies

	for (int i = 0; i < timer.spawn; i++)
		DrawTexture(objects->enemy[i].tex, objects->enemy[i].pos.x, objects->enemy[i].pos.y, WHITE);


	// Bullets

	for (int i = 0; i < BULLET_MAX; i++) {
		if (objects->bullet[i].active)
			DrawCircleV(objects->bullet[i].pos, 10 * SCALE, YELLOW);
	}
}
