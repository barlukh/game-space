#include "config.h"

void randomize_spawn(void)
{
	randomSpawnPos[0][0] = GetRandomValue(0, SCREEN_WIDTH);
	randomSpawnPos[0][1] = -SCREEN_HEIGHT * 0.07f;
	randomSpawnPos[1][0] = GetRandomValue(0, SCREEN_WIDTH);
	randomSpawnPos[1][1] = SCREEN_HEIGHT * 1.07f;
	randomSpawnPos[2][0] = -SCREEN_WIDTH * 0.07f;
	randomSpawnPos[2][1] = GetRandomValue(0, SCREEN_HEIGHT);
	randomSpawnPos[3][0] = SCREEN_WIDTH * 1.07f;
	randomSpawnPos[3][1] = GetRandomValue(0, SCREEN_HEIGHT);
}
