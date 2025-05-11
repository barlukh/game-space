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

#define SCREEN_WIDTH GetScreenWidth()  
#define SCREEN_HEIGHT GetScreenHeight()
#define SCALE fmin((float)GetScreenWidth() / 3840.0f, (float)GetScreenHeight() / 2160.0f)
#define GAME_TITLE "Space Jam"
#define SCREEN_FPS 60

#define PLAYER_SPEED 1000

#define ENEMY_SPEED 400.0f
#define ENEMY_MAX 100

#define BULLET_RATE 0.07
#define BULLET_SPEED 4000.0f
#define BULLET_MAX 50

#define FRAME_THRESHOLD 0.2f
#define SPAWN_THRESHOLD 3.0f
#define TOTAL_FRAMES 2


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
	StaticObject explosion;
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
// Global Variables
//----------------------------------------------------------------------------------

extern int score;  
extern int randomSidePick;
extern int randomSpawnPos[4][2];

extern Time timer;


//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------

/** Displays intro screen
 * @param currentState Current state of the game
 * @param objects Pointer to struct of all game objects
 * @return None
 */
void intro(GameState *currentState, Graphics *objects);

/** Controls player input and updates player position
 * @param objects Pointer to struct of all game objects
 * @return None
 */
void controls_player(Graphics *objects);

/** Checks for collisions of sprites
 * @param currentState Current state of the game
 * @param objects Pointer to struct of all game objects
 * @return None
 */
void check_collisions(GameState *currentState, Graphics *objects);

/** Draws all necessary sprites on the screen
 * @param objects Pointer to struct of all game objects
 * @return None
 */
void objects_draw(Graphics *objects);

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
