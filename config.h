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
#define ENEMY_SPEED 6.0f
#define MAX_ENEMIES 100
#define MAX_BULLETS 50


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

typedef struct Enemy {
	Vector2 enemyPos;
	Rectangle enemyRec;
	Vector2 enemyDir;
} Enemy;

typedef struct FrameCounter {
	int frame;			// Current frame displayed
	float threshold;	// Threshold value for the next frame
	float elapsed;		// Time elapsed
} FrameCounter;

typedef struct SpawnCounter {
	int count;			// Current number of enemies spawned
	float threshold;	// Threshold value for the next enemy
	float elapsed;		// Time elapsed
} SpawnCounter;

typedef struct Visuals {
	Texture2D blueplanet;
	Texture2D earth;
	Texture2D enemy;
	Texture2D player;
	Texture2D purpleplanet;
	Texture2D redplanet;
	Texture2D rocketwhite;
	Texture2D satellite;
	Texture2D saturn;
	Texture2D sun;
	Texture2D text;
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
void controls_player(Vector2 *playerPos, Texture2D player);
void check_collisions(Enemy *enemies, Vector2 *playerPos, Rectangle playerRec, int randomPick, int randomSide[4][2], GameState *currentState, Bullet *bullets, SpawnCounter *spawn, int *score);
void randomizer(int randomSide[4][2]);
void textures_draw(Visuals space, Texture2D playerTex, Vector2 playerPos, Texture2D enemyTex, Enemy *enemies, SpawnCounter spawn, int *score);
Visuals textures_load(Visuals space);
void textures_unload(Visuals space);


#endif
