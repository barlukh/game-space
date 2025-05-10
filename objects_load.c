#include "config.h"

void objects_load(Graphics *objects)
{
	// Enemy
	
	objects->enemy[0].tex = LoadTexture("graphics/ufo.png");

	for (int i = 0; i < ENEMY_MAX; i++) {
		randomSidePick = GetRandomValue(0, 3);
		randomize_spawn();

		objects->enemy[i].tex = objects->enemy[0].tex;

		objects->enemy[i].pos = (Vector2){randomSpawnPos[randomSidePick][0],
			randomSpawnPos[randomSidePick][1]};

		objects->enemy[i].rec = (Rectangle){objects->enemy[i].pos.x, objects->enemy[i].pos.y,
			objects->enemy[i].tex.width, objects->enemy[i].tex.height};

		objects->enemy[i].dir = (Vector2){objects->player.pos.x - objects->enemy[i].pos.x,
			objects->player.pos.y - objects->enemy[i].pos.y};
	}


	// Player
	
	objects->player.tex[0] = LoadTexture("graphics/astronaut1.png");
	objects->player.tex[1] = LoadTexture("graphics/astronaut2.png");
	
	objects->player.pos = (Vector2){(SCREEN_WIDTH / 2.0) - (objects->player.tex[0].width / 2.0),
		(SCREEN_HEIGHT / 2.0) - (objects->player.tex[0].height / 2.0)};

	objects->player.rec = (Rectangle){objects->player.pos.x, objects->player.pos.y,
		objects->player.tex[0].width, objects->player.tex[0].height};


	// Static
	
	objects->blueplanet.tex = LoadTexture("graphics/blueplanet.png");
	objects->blueplanet.pos = (Vector2){1500 * SCALE_X, 200 * SCALE_Y};

	objects->earth.tex = LoadTexture("graphics/earth.png");
	objects->earth.pos = (Vector2){1792 * SCALE_X, 952 * SCALE_Y};
	
	objects->purpleplanet.tex = LoadTexture("graphics/purpleplanet.png");
	objects->purpleplanet.pos = (Vector2){600 * SCALE_X, 1300 * SCALE_Y};
	
	objects->redplanet.tex = LoadTexture("graphics/redplanet.png");
	objects->redplanet.pos = (Vector2){400 * SCALE_X, 500 * SCALE_Y};
	
	objects->rocketwhite.tex = LoadTexture("graphics/rocketwhite.png");
	objects->rocketwhite.pos = (Vector2){100 * SCALE_X, 1900 * SCALE_Y};
	
	objects->satellite.tex = LoadTexture("graphics/satellite.png");
	objects->satellite.pos = (Vector2){2050 * SCALE_X, 850 * SCALE_Y};
	
	objects->saturn.tex = LoadTexture("graphics/saturn.png");
	objects->saturn.pos = (Vector2){800 * SCALE_X, 100 * SCALE_Y};
	
	objects->sun.tex = LoadTexture("graphics/sun.png");
	objects->sun.pos = (Vector2){1000 * SCALE_X, 500 * SCALE_Y};
	
	objects->title.tex = LoadTexture("graphics/title.png");
	objects->title.pos = (Vector2){1120 * SCALE_X, 1350 * SCALE_Y};
	
	objects->whiteshootingstar.tex = LoadTexture("graphics/whiteshootingstar.png");
	objects->whiteshootingstar.pos = (Vector2){1000 * SCALE_X, 300 * SCALE_Y};
	
	objects->whitestar.tex = LoadTexture("graphics/whitestar.png");
	objects->whitestar.pos = (Vector2){3500 * SCALE_X, 700 * SCALE_Y};
	
	objects->whitestars1.tex = LoadTexture("graphics/whitestars1.png");
	objects->whitestars1.pos = (Vector2){3000 * SCALE_X, 400 * SCALE_Y};
	
	objects->whitestars2.tex = LoadTexture("graphics/whitestars2.png");
	objects->whitestars2.pos = (Vector2){200 * SCALE_X, 1100 * SCALE_Y};
	
	objects->yellowhalfmoon.tex = LoadTexture("graphics/yellowhalfmoon.png");
	objects->yellowhalfmoon.pos = (Vector2){100 * SCALE_X, 100 * SCALE_Y};
	
	objects->yellowshootingstar.tex = LoadTexture("graphics/yellowshootingstar.png");
	objects->yellowshootingstar.pos = (Vector2){300 * SCALE_X, 150 * SCALE_Y};
	
	objects->yellowstars.tex = LoadTexture("graphics/yellowstars.png");
	objects->yellowstars.pos = (Vector2){3650 * SCALE_X, 100 * SCALE_Y};
}
