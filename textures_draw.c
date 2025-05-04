#include "config.h"
#include <raylib.h>

void textures_draw(Visuals space, Texture2D playerTex, Vector2 playerPos, Texture2D enemyTex, Enemy *enemies, int *score)
{
	DrawTexture(space.rocketwhite, 100, 1900, WHITE);
	DrawTexture(space.whiteshootingstar, 1000, 300, WHITE);
	DrawTexture(space.whitestar, 3500, 700, WHITE);
	DrawTexture(space.whitestars1, 3000, 400, WHITE);
	DrawTexture(space.whitestars2, 200, 1100, WHITE);
	DrawTexture(space.yellowhalfmoon, 100, 100, WHITE);
	DrawTexture(space.yellowshootingstar, 300, 150, WHITE);
	DrawTexture(space.yellowstars, 3650, 100, WHITE);

	DrawTexture(playerTex, playerPos.x, playerPos.y, WHITE);
	DrawText(TextFormat("Score: %d", *score), 20, SCREEN_HEIGHT-100, 100, WHITE);

	for (int i = 0; i < MAX_ENEMIES; i++)
		DrawTexture(enemyTex, enemies[i].enemyPos.x, enemies[i].enemyPos.y, WHITE);
}
