#include "config.h"

void check_collisions(GameState *currentState, Graphics *objects)
{
	for (int i = 0; i < timer.spawn; i++) {
		if (CheckCollisionRecs(objects.enemiey[i].rec, playerRec)) {
			playerPos->x = SCREEN_WIDTH / 2.0;
			playerPos->y = SCREEN_HEIGHT / 2.0;
			
			for (int i = 0; i < spawn->count; i++) {
				randomSidePick = GetRandomValue(0, 3);
				randomize_spawn(randomSpawnPos);
				enemies[i].enemyPos.x = randomSpawnPos[randomSidePick][0];
				enemies[i].enemyPos.y = randomSpawnPos[randomSidePick][1];
			}
			
			spawn->count = 1;

			for (int i = 0; i < BULLET_MAX; i++) {
				for (int j = 0; j < spawn->count; j++) {
					bullets[i].active = false;
				}
			}
			
			*currentState = INTRO;
		}
	}

	for (int i = 0; i < BULLET_MAX; i++) {
		for (int j = 0; j < spawn->count; j++) {
		if (CheckCollisionCircleRec(bullets[i].pos, 10, enemies[j].enemyRec)) {
			bullets[i].active = false;
			randomize_spawn(randomSpawnPos);
			(*score)++;
			randomSidePick = GetRandomValue(0, 3);
			DrawTexture(LoadTexture("graphics/explosion.png"), enemies[j].enemyPos.x, enemies[j].enemyPos.y, WHITE);
			enemies[j].enemyPos.x = randomSpawnPos[randomSidePick][0];
			enemies[j].enemyPos.y = randomSpawnPos[randomSidePick][1];
			}
		}
	}
}
