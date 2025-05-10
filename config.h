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
#define ENEMY_MAX 100

#define BULLET_SPEED 30.0f
#define BULLET_MAX 50

#define FRAME_THRESHOLD 0.2f
#define SPAWN_THRESHOLD 3.0f
#define TOTAL_FRAMES 2


//----------------------------------------------------------------------------------
// Global Variables
//----------------------------------------------------------------------------------

extern int score;  
extern int randomSidePick;
extern int randomSpawnPos[4][2];

extern Time timer;


//----------------------------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------------------------

typedef enum GameState {
	INTRO = 0,
	GAMEPLAY
} GameState;

typedef struct Time {
	int frame;				// Current frame displayed
	int spawn;				// Current number of enemies spawned
	float elapsedFrame;		// Time elapsed for frame animation
	float elapsedSpawn;		// Time elapsed for enemy spawn
} Time;

typedef struct BulletObject {
	Vector2 pos;
	Vector2 dir;
	bool active;
} BulletObject;

typedef struct EnemyObject {
	Texture2D tex;
	Vector2 pos;
	Rectangle rec;
	Vector2 dir;
} EnemyObject;

typedef struct PlayerObject {
	Texture2D tex[2];
	Vector2 pos;
	Rectangle rec;
} PlayerObject;

typedef struct StaticObject {
	Texture2D tex;
	Vector2 pos;
} StaticObject;

typedef struct Graphics {
	BulletObject bullet[BULLET_MAX];
	EnemyObject enemy[ENEMY_MAX];
	PlayerObject player;
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

void intro(GameState *currentState, Graphics objects, int *score);
void controls_bullets(Vector2 *bulletDir);
void controls_player(Graphics *objects);
void check_collisions(EnemyObject *enemies, Vector2 *playerPos, Rectangle playerRec, int randomSidePick, int randomSpawnPos[4][2], GameState *currentState, BulletObject *bullets, SpawnCounter *spawn, int *score, Graphics objects);
void objects_draw(Graphics objects, Texture2D playerTex, Vector2 playerPos, Texture2D enemyTex, EnemyObject *enemies, SpawnCounter spawn, int *score);

/** Loads textures, initializes rectanlges and other attributes of objects
 * @param objects Pointer to struct of all game objects
 * @return None
 */
void objects_load(Graphics *objects);

/** Unloads all textures
 * @param objects Pointer to struct of all game objects
 * @return None
 */
void objects_unload(Graphics *objects);

/** Updates all objects
 * @param objects Pointer to struct of all game objects
 * @return None
 */
void objects_update(Graphics *objects);

/** Randomizes spawn positions of enemy sprites
 * @return None
 */
void randomize_spawn(void);

#endif
