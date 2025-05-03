#ifndef CONFIG_H
#define CONFIG_H


//----------------------------------------------------------------------------------
// Library Headers
//----------------------------------------------------------------------------------
#include <raylib.h>
#include <math.h>


//----------------------------------------------------------------------------------
// Macro Definitions
//----------------------------------------------------------------------------------
#define SCREEN_WIDTH 3840
#define SCREEN_HEIGHT 2160
#define GAME_TITLE "Space Jam"
#define SCREEN_FPS 60
#define PLAYER_SPEED 20
#define ENEMY_SPEED 10.0f
#define MAX_BULLET 100


//----------------------------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------------------------

typedef struct Bullet {
	Vector2 position;
	Vector2 direction;
	bool active;
} Bullet;

typedef enum GameState {
	INTRO = 0,
	GAMEPLAY
} GameState;

typedef struct Visuals {
	Texture2D blueplanet;
	Texture2D earth;
	Texture2D purpleplanet;
	Texture2D redplanet;
	Texture2D rocketwhite;
	Texture2D satellite;
	Texture2D saturn;
	Texture2D sun;
	Texture2D ufo;
	Texture2D whiteshootingstar;
	Texture2D whitestar;
	Texture2D whitestars1;
	Texture2D whitestars2;
	Texture2D yellowhalfmoon;
	Texture2D yellowshootingstar;
	Texture2D yellowstars;
} Visuals;


//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------

void intro(GameState *currentState, Visuals space);
void controls_bullets(Vector2 *bulletDir);
void controls_player(Vector2 *playerPos, Texture2D *player);
void textures_draw(Visuals space);
Visuals textures_load(Visuals space);
void textures_unload(Visuals space);

#endif
