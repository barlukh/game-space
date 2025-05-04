#include "config.h"
#include <stdio.h>

void check_collisions(Enemy *enemies, Vector2 *playerPos, Rectangle playerRec, int randomPick, int randomSide[4][2], GameState *currentState, Bullet *bullets, int *score)
{
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (CheckCollisionRecs(enemies[i].enemyRec, playerRec)) {
			playerPos->x = SCREEN_WIDTH / 2.0;
			playerPos->y = SCREEN_HEIGHT / 2.0;
			
			for (int i = 0; i < MAX_ENEMIES; i++) {
				randomPick = GetRandomValue(0, 3);
				randomizer(randomSide);
				enemies[i].enemyPos.x = randomSide[randomPick][0];
				enemies[i].enemyPos.y = randomSide[randomPick][1];
			}
			*currentState = INTRO;
			*score = 0;
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		for (int j = 0; j < MAX_ENEMIES; j++) {
		if (CheckCollisionCircleRec(bullets[i].position, 10, enemies[j].enemyRec)) {
			bullets[i].active = false;
			randomizer(randomSide);
			(*score)++;
			randomPick = GetRandomValue(0, 3);
			enemies[j].enemyPos.x = randomSide[randomPick][0];
			enemies[j].enemyPos.y = randomSide[randomPick][1];
			}
		}
	}
}
