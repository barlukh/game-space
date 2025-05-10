#include "config.h"

void objects_load(Graphics *objects)
{
	// Bullets

	for (int i = 0; i < BULLET_MAX; i++) {
		objects->bullet[i].active = false;
	}

	
	// Enemies
	
	Image img = LoadImage("graphics/ufo.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->enemy[0].tex = LoadTextureFromImage(img);
	UnloadImage(img);

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
	
	Image img = LoadImage("graphics/astronaut1.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->player.tex[0] = LoadTextureFromImage(img);
	UnloadImage(img);

	Image img = LoadImage("graphics/astronaut2.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->player.tex[1] = LoadTextureFromImage(img);
	UnloadImage(img);
	
	objects->player.pos = (Vector2){(SCREEN_WIDTH / 2.0) - (objects->player.tex[0].width / 2.0),
		(SCREEN_HEIGHT / 2.0) - (objects->player.tex[0].height / 2.0)};

	objects->player.rec = (Rectangle){objects->player.pos.x, objects->player.pos.y,
		objects->player.tex[0].width, objects->player.tex[0].height};


	// Static objects
	
	Image img = LoadImage("graphics/blueplanet.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->blueplanet.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->blueplanet.pos = (Vector2){1500 * SCALE_X, 200 * SCALE_Y};

	Image img = LoadImage("graphics/earth.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->earth.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->earth.pos = (Vector2){1792 * SCALE_X, 952 * SCALE_Y};
	
	Image img = LoadImage("graphics/purpleplanet.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->purpleplanet.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->purpleplanet.pos = (Vector2){600 * SCALE_X, 1300 * SCALE_Y};
	
	Image img = LoadImage("graphics/redplanet.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->redplanet.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->redplanet.pos = (Vector2){400 * SCALE_X, 500 * SCALE_Y};
	
	Image img = LoadImage("graphics/rocketwhite.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->rocketwhite.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->rocketwhite.pos = (Vector2){100 * SCALE_X, 1900 * SCALE_Y};
	
	Image img = LoadImage("graphics/satellite.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->satellite.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->satellite.pos = (Vector2){2050 * SCALE_X, 850 * SCALE_Y};
	
	Image img = LoadImage("graphics/saturn.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->saturn.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->saturn.pos = (Vector2){800 * SCALE_X, 100 * SCALE_Y};
	
	Image img = LoadImage("graphics/sun.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->sun.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->sun.pos = (Vector2){1000 * SCALE_X, 500 * SCALE_Y};
	
	Image img = LoadImage("graphics/title.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->title.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->title.pos = (Vector2){1120 * SCALE_X, 1350 * SCALE_Y};
	
	Image img = LoadImage("graphics/whiteshootingstar.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->whiteshootingstar.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whiteshootingstar.pos = (Vector2){1000 * SCALE_X, 300 * SCALE_Y};
	
	Image img = LoadImage("graphics/whitestar.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->whitestar.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whitestar.pos = (Vector2){3500 * SCALE_X, 700 * SCALE_Y};
	
	Image img = LoadImage("graphics/whitestars1.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->whitestars1.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whitestars1.pos = (Vector2){3000 * SCALE_X, 400 * SCALE_Y};
	
	Image img = LoadImage("graphics/whitestars2.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->whitestars2.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whitestars2.pos = (Vector2){200 * SCALE_X, 1100 * SCALE_Y};
	
	Image img = LoadImage("graphics/yellowhalfmoon.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->yellowhalfmoon.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->yellowhalfmoon.pos = (Vector2){100 * SCALE_X, 100 * SCALE_Y};
	
	Image img = LoadImage("graphics/yellowshootingstar.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->yellowshootingstar.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->yellowshootingstar.pos = (Vector2){300 * SCALE_X, 150 * SCALE_Y};
	
	Image img = LoadImage("graphics/yellowstars.png");
	ImageResize(&img, img.width * SCALE_X, img.height * SCALE_Y);
	objects->yellowstars.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->yellowstars.pos = (Vector2){3650 * SCALE_X, 100 * SCALE_Y};
}
