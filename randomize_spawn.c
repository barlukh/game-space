#include "config.h"

void randomize_spawn(void)
{
    randomSpawnPos[0][0] = GetRandomValue(0, SCREEN_WIDTH);
    randomSpawnPos[0][1] = -150;
    randomSpawnPos[1][0] = GetRandomValue(0, SCREEN_WIDTH);
    randomSpawnPos[1][1] = SCREEN_HEIGHT + 150;
    randomSpawnPos[2][0] = -150;
    randomSpawnPos[2][1] = GetRandomValue(0, SCREEN_HEIGHT);
    randomSpawnPos[3][0] = SCREEN_WIDTH + 150;
    randomSpawnPos[3][1] = GetRandomValue(0, SCREEN_HEIGHT);
}
