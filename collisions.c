#include "config.h"

void check_collisions(GameState *currentState, Graphics *objects)
{
	// Checks for collisions between the player and enemy sprites, resets all sprites on collision
	
	for (int i = 0; i < timer.spawn; i++) {
		if (CheckCollisionRecs(objects->enemy[i].rec, objects->player.rec)) {
			objects->player.pos = (Vector2){(SCREEN_WIDTH / 2.0) - (objects->player.tex[0].width / 2.0),
				(SCREEN_HEIGHT / 2.0) - (objects->player.tex[0].height / 2.0)};
			
			for (int i = 0; i < timer.spawn; i++) {
				randomSidePick = GetRandomValue(0, 3);
				randomize_spawn();
				objects->enemy[i].pos = (Vector2){randomSpawnPos[randomSidePick][0],
					randomSpawnPos[randomSidePick][1]};
			}
			
			timer.spawn = 0;

			for (int i = 0; i < BULLET_MAX; i++) {
				objects->bullet[i].active = false;
			}
			
			*currentState = INTRO;
		}
	}


	// Checks for collision between bullets and enemy sprites, resets both sprites on collision

	for (int i = 0; i < BULLET_MAX; i++) {
		for (int j = 0; j < timer.spawn; j++) {
			if (CheckCollisionCircleRec(objects->bullet[i].pos, 10 * SCALE, objects->enemy[j].rec)) {
				objects->bullet[i].active = false;
				randomSidePick = GetRandomValue(0, 3);
				randomize_spawn();
				DrawTexture(objects->explosion.tex, objects->enemy[j].pos.x, objects->enemy[j].pos.y, WHITE);
				objects->enemy[j].pos = (Vector2){randomSpawnPos[randomSidePick][0],
					randomSpawnPos[randomSidePick][1]};
				score++;
			}
		}
	}
}

