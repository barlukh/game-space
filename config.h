#ifndef CONFIG_H
#define CONFIG_H

//----------------------------------------------------------------------------------
// Library Headers
//----------------------------------------------------------------------------------
#include <raylib.h>

//----------------------------------------------------------------------------------
// Macro Definitions
//----------------------------------------------------------------------------------
#define SCREEN_WIDTH 3840
#define SCREEN_HEIGHT 2160
#define GAME_TITLE "Space Jam"
#define SCREEN_FPS 60

//----------------------------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------------------------
// Enumeration for different states of the game
typedef enum GameState {
	INTRO = 0,
	GAMEPLAY
} GameState;

typedef struct Visuals {
	Texture2D blueplanet;
	Texture2D earth;
	Texture2D fullmoon;
	Texture2D hurricane;
	Texture2D purpleplanet;
	Texture2D redmoon;
	Texture2D redplanet;
	Texture2D satellite;
	Texture2D saturn;
	Texture2D sun;
	Texture2D whitemoon;
	Texture2D whiteshootingstar;
	Texture2D whitestar;
	Texture2D whitestars1;
	Texture2D whitestars2;
	Texture2D yellowhalfmoon;
	Texture2D yellowshootingstar;
	Texture2D yellowstar;
	Texture2D yellowstars1;
	Texture2D yellowstars2;
} Visuals;

//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------
void intro(GameState *currentState, Visuals visuals);

#endif
