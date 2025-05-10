#include "config.h"

void objects_draw(Graphics objects, Texture2D playerTex, Vector2 playerPos, Texture2D enemyTex, EnemyObject *enemies, SpawnCounter spawn, int *score)
{
	DrawTextureEx(objects.rocketwhite.texture, objects.rocketwhite.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whiteshootingstar.texture, objects.whiteshootingstar.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whitestar.texture, objects.whitestar.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whitestars1.texture, objects.whitestars1.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.whitestars2.texture, objects.whitestars2.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.yellowhalfmoon.texture, objects.yellowhalfmoon.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.yellowshootingstar.texture, objects.yellowshootingstar.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);
	DrawTextureEx(objects.yellowstars.texture, objects.yellowstars.position, 0.0f, fmin(SCALE_X, SCALE_Y), WHITE);

	DrawTexture(playerTex, playerPos.x, playerPos.y, WHITE);
	DrawText(TextFormat("Score: %d", *score), 20, SCREEN_HEIGHT-100, 100, WHITE);

	for (int i = 0; i < spawn.count; i++)
		DrawTexture(enemyTex, enemies[i].enemyPos.x, enemies[i].enemyPos.y, WHITE);
}
