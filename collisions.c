#include "config.h"

void check_collisions(Enemy *enemies, Vector2 *playerPos, Rectangle playerRec, int randomPick, int randomSide[4][2], GameState *currentState, Bullet *bullets, SpawnCounter *spawn, int *score)
{
	for (int i = 0; i < spawn->count; i++) {
		if (CheckCollisionRecs(enemies[i].enemyRec, playerRec)) {
			playerPos->x = SCREEN_WIDTH / 2.0;
			playerPos->y = SCREEN_HEIGHT / 2.0;
			
			for (int i = 0; i < spawn->count; i++) {
				randomPick = GetRandomValue(0, 3);
				randomizer(randomSide);
				enemies[i].enemyPos.x = randomSide[randomPick][0];
				enemies[i].enemyPos.y = randomSide[randomPick][1];
			}
			
			spawn->count = 1;

			for (int i = 0; i < MAX_BULLETS; i++) {
				for (int j = 0; j < spawn->count; j++) {
					bullets[i].active = false;
				}
			}
			
			*currentState = INTRO;
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		for (int j = 0; j < spawn->count; j++) {
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
