#include "config.h"

void randomizer(int randomSide[4][2])
{
    randomSide[0][0] = GetRandomValue(0, SCREEN_WIDTH);
    randomSide[0][1] = -150;
    randomSide[1][0] = GetRandomValue(0, SCREEN_WIDTH);
    randomSide[1][1] = SCREEN_HEIGHT + 150;
    randomSide[2][0] = -150;
    randomSide[2][1] = GetRandomValue(0, SCREEN_HEIGHT);
    randomSide[3][0] = SCREEN_WIDTH + 150;
    randomSide[3][1] = GetRandomValue(0, SCREEN_HEIGHT);
}
