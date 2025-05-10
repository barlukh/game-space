#include "config.h"

void controls_player(Graphics *objects)
{
	if (IsKeyDown(KEY_A))
		objects->player.pos.x -= PLAYER_SPEED;
	if (IsKeyDown(KEY_S))
		objects->player.pos.y += PLAYER_SPEED;
	if (IsKeyDown(KEY_D))
		objects->player.pos.x += PLAYER_SPEED;
	if (IsKeyDown(KEY_W))
		objects->player.pos.y -= PLAYER_SPEED;

	if (objects->player.pos.x <= 0)
		objects->player.pos.x = 0;
	if (objects->player.pos.x > SCREEN_WIDTH - objects->player.tex->width)
		objects->player.pos.x = SCREEN_WIDTH - objects->player.tex->width;
	if (objects->player.pos.y <= 0)
		objects->player.pos.y = 0;
	if (objects->player.pos.y > SCREEN_HEIGHT - objects->player.tex->height)
		objects->player.pos.y = SCREEN_HEIGHT - objects->player.tex->height;
}
