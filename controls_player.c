#include "config.h"

void controls_player(Vector2 *playerPos, Texture2D *player)
{
	if (IsKeyDown(KEY_A))
		playerPos->x -= PLAYER_SPEED;
	if (IsKeyDown(KEY_S))
		playerPos->y += PLAYER_SPEED;
	if (IsKeyDown(KEY_D))
		playerPos->x += PLAYER_SPEED;
	if (IsKeyDown(KEY_W))
		playerPos->y -= PLAYER_SPEED;

	if (playerPos->x <= 0)
		playerPos->x = 0;
	if (playerPos->x > SCREEN_WIDTH - player->width)
		playerPos->x = SCREEN_WIDTH - player->width;
	if (playerPos->y <= 0)
		playerPos->y = 0;
	if (playerPos->y > SCREEN_HEIGHT - player->height)
		playerPos->y = SCREEN_HEIGHT - player->height;
}
