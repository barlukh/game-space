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

#define SCREEN_WIDTH 2560 // GetScreenWidth()
#define SCREEN_HEIGHT 1440 //GetScreenHeight()
#define SCALE_X (float)GetScreenWidth() / 3840.0f
#define SCALE_Y (float)GetScreenHeight() / 2160.0f
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

typedef struct Enemy {
	Texture2D enemyTex;
	Vector2 enemyPos;
	Rectangle enemyRec;
	Vector2 enemyDir;
} Enemy;

typedef struct StaticObject {
	Texture2D texture;
	Vector2 position;
} StaticObject;

typedef struct Graphics {
	StaticObject blueplanet;
	StaticObject earth;
	StaticObject purpleplanet;
	StaticObject redplanet;
	StaticObject rocketwhite;
	StaticObject satellite;
	StaticObject saturn;
	StaticObject sun;
	StaticObject title;
	StaticObject whiteshootingstar;
	StaticObject whitestar;
	StaticObject whitestars1;
	StaticObject whitestars2;
	StaticObject yellowhalfmoon;
	StaticObject yellowshootingstar;
	StaticObject yellowstars;
} Graphics;


//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------

void intro(GameState *currentState, Graphics space, int *score);
void controls_bullets(Vector2 *bulletDir);
void controls_player(Vector2 *playerPos, Texture2D player);
void check_collisions(Enemy *enemies, Vector2 *playerPos, Rectangle playerRec, int randomPick, int randomSide[4][2], GameState *currentState, Bullet *bullets, SpawnCounter *spawn, int *score, Graphics space);
void randomizer(int randomSide[4][2]);
void textures_draw(Graphics space, Texture2D playerTex, Vector2 playerPos, Texture2D enemyTex, Enemy *enemies, SpawnCounter spawn, int *score);
Graphics textures_load(Graphics space);
void textures_unload(Graphics space);


#endif
