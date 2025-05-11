#include "config.h"

void objects_load(Graphics *objects)
{
	// Bullets

	for (int i = 0; i < BULLET_MAX; i++) {
		objects->bullet[i].active = false;
	}

	
	// Enemies
	
	Image img = LoadImage("graphics/ufo.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
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
	
	img = LoadImage("graphics/astronaut1.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->player.tex[0] = LoadTextureFromImage(img);
	UnloadImage(img);

	img = LoadImage("graphics/astronaut2.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->player.tex[1] = LoadTextureFromImage(img);
	UnloadImage(img);
	
	objects->player.pos = (Vector2){(SCREEN_WIDTH / 2.0) - (objects->player.tex[0].width / 2.0),
		(SCREEN_HEIGHT / 2.0) - (objects->player.tex[0].height / 2.0)};

	objects->player.rec = (Rectangle){objects->player.pos.x, objects->player.pos.y,
		objects->player.tex[0].width, objects->player.tex[0].height};


	// Static objects
	
	img = LoadImage("graphics/blueplanet.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->blueplanet.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->blueplanet.pos = (Vector2){ (1500 / 3840.0f) * GetScreenWidth(), (200 / 2160.0f) * GetScreenHeight() };

	img = LoadImage("graphics/earth.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->earth.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->earth.pos = (Vector2){ (1792 / 3840.0f) * GetScreenWidth(), (952 / 2160.0f) * GetScreenHeight() };

	img = LoadImage("graphics/explosion.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->explosion.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->explosion.pos = (Vector2){ (0 / 3840.0f) * GetScreenWidth(), (0 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/purpleplanet.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->purpleplanet.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->purpleplanet.pos = (Vector2){ (600 / 3840.0f) * GetScreenWidth(), (1300 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/redplanet.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->redplanet.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->redplanet.pos = (Vector2){ (400 / 3840.0f) * GetScreenWidth(), (500 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/rocketwhite.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->rocketwhite.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->rocketwhite.pos = (Vector2){ (100 / 3840.0f) * GetScreenWidth(), (1900 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/satellite.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->satellite.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->satellite.pos = (Vector2){ (2050 / 3840.0f) * GetScreenWidth(), (850 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/saturn.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->saturn.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->saturn.pos = (Vector2){ (800 / 3840.0f) * GetScreenWidth(), (100 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/sun.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->sun.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->sun.pos = (Vector2){ (1000 / 3840.0f) * GetScreenWidth(), (500 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/title.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->title.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->title.pos = (Vector2){ (1120 / 3840.0f) * GetScreenWidth(), (1350 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/whiteshootingstar.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->whiteshootingstar.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whiteshootingstar.pos = (Vector2){ (1000 / 3840.0f) * GetScreenWidth(), (300 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/whitestar.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->whitestar.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whitestar.pos = (Vector2){ (3500 / 3840.0f) * GetScreenWidth(), (700 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/whitestars1.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->whitestars1.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whitestars1.pos = (Vector2){ (3000 / 3840.0f) * GetScreenWidth(), (400 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/whitestars2.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->whitestars2.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->whitestars2.pos = (Vector2){ (200 / 3840.0f) * GetScreenWidth(), (1100 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/yellowhalfmoon.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->yellowhalfmoon.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->yellowhalfmoon.pos = (Vector2){ (100 / 3840.0f) * GetScreenWidth(), (100 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/yellowshootingstar.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->yellowshootingstar.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->yellowshootingstar.pos = (Vector2){ (300 / 3840.0f) * GetScreenWidth(), (150 / 2160.0f) * GetScreenHeight() };
	
	img = LoadImage("graphics/yellowstars.png");
	ImageResize(&img, img.width * SCALE, img.height * SCALE);
	objects->yellowstars.tex = LoadTextureFromImage(img);
	UnloadImage(img);
	objects->yellowstars.pos = (Vector2){ (3650 / 3840.0f) * GetScreenWidth(), (100 / 2160.0f) * GetScreenHeight() };
}
