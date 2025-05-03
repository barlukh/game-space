#include "config.h"

void controls_bullets(Vector2 *bulletDir)
{
	if (IsKeyDown(KEY_RIGHT))
		*bulletDir = (Vector2){1.0f, 0.0f};
	if (IsKeyDown(KEY_LEFT))
		*bulletDir = (Vector2){-1.0f, 0.0f};
	if (IsKeyDown(KEY_UP))
		*bulletDir = (Vector2){0.0f, -1.0f};
	if (IsKeyDown(KEY_DOWN))
		*bulletDir = (Vector2){0.0f, 1.0f};
	if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP))
		*bulletDir = (Vector2){1.0f, -1.0f};
	if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN))
		*bulletDir = (Vector2){1.0f, 1.0f};
	if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN))
		*bulletDir = (Vector2){-1.0f, 1.0f};
	if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP))
		*bulletDir = (Vector2){-1.0f, -1.0f};
}