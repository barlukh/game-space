#include "config.h"

void objects_draw(Graphics objects, Texture2D playerTex, Vector2 playerPos, Texture2D enemyTex, EnemyObject *enemies, SpawnCounter spawn, int *score)
{
	DrawTextureEx(objects.rocketwhite.tex, objects.rocketwhite.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whiteshootingstar.tex, objects.whiteshootingstar.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whitestar.tex, objects.whitestar.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whitestars1.tex, objects.whitestars1.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whitestars2.tex, objects.whitestars2.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.yellowhalfmoon.tex, objects.yellowhalfmoon.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.yellowshootingstar.tex, objects.yellowshootingstar.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.yellowstars.tex, objects.yellowstars.pos, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);

	DrawTexture(playerTex, playerPos.x, playerPos.y, WHITE);
	DrawText(TextFormat("Score: %d", *score), 20, SCREEN_HEIGHT-100, 100, WHITE);

	for (int i = 0; i < spawn.count; i++)
		DrawTexture(enemyTex, enemies[i].enemyPos.x, enemies[i].enemyPos.y, WHITE);
}
