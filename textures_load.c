#include "config.h"

Graphics textures_load(Graphics objects)
{
	objects.blueplanet.texture = LoadTexture("graphics/blueplanet.png");
	objects.earth.texture = LoadTexture("graphics/earth.png");
	objects.purpleplanet.texture = LoadTexture("graphics/purpleplanet.png");
	objects.redplanet.texture = LoadTexture("graphics/redplanet.png");
	objects.rocketwhite.texture = LoadTexture("graphics/rocketwhite.png");
	objects.satellite.texture = LoadTexture("graphics/satellite.png");
	objects.saturn.texture = LoadTexture("graphics/saturn.png");
	objects.sun.texture = LoadTexture("graphics/sun.png");
	objects.title.texture = LoadTexture("graphics/title.png");
	objects.whiteshootingstar.texture = LoadTexture("graphics/whiteshootingstar.png");
	objects.whitestar.texture = LoadTexture("graphics/whitestar.png");
	objects.whitestars1.texture = LoadTexture("graphics/whitestars1.png");
	objects.whitestars2.texture = LoadTexture("graphics/whitestars2.png");
	objects.yellowhalfmoon.texture = LoadTexture("graphics/yellowhalfmoon.png");
	objects.yellowshootingstar.texture = LoadTexture("graphics/yellowshootingstar.png");
	objects.yellowstars.texture = LoadTexture("graphics/yellowstars.png");

	objects.blueplanet.position = (Vector2){1500 * SCALE_X, 200 * SCALE_Y};
	objects.earth.position = (Vector2){1792 * SCALE_X, 952 * SCALE_Y};
	objects.purpleplanet.position = (Vector2){600 * SCALE_X, 1300 * SCALE_Y};
	objects.redplanet.position = (Vector2){400 * SCALE_X, 500 * SCALE_Y};
	objects.rocketwhite.position = (Vector2){100 * SCALE_X, 1900 * SCALE_Y};
	objects.satellite.position = (Vector2){2050 * SCALE_X, 850 * SCALE_Y};
	objects.saturn.position = (Vector2){800 * SCALE_X, 100 * SCALE_Y};
	objects.sun.position = (Vector2){1000 * SCALE_X, 500 * SCALE_Y};
	objects.title.position = (Vector2){1120 * SCALE_X, 1350 * SCALE_Y};
	objects.whiteshootingstar.position = (Vector2){1000 * SCALE_X, 300 * SCALE_Y};
	objects.whitestar.position = (Vector2){3500 * SCALE_X, 700 * SCALE_Y};
	objects.whitestars1.position = (Vector2){3000 * SCALE_X, 400 * SCALE_Y};
	objects.whitestars2.position = (Vector2){200 * SCALE_X, 1100 * SCALE_Y};
	objects.yellowhalfmoon.position = (Vector2){100 * SCALE_X, 100 * SCALE_Y};
	objects.yellowshootingstar.position = (Vector2){300 * SCALE_X, 150 * SCALE_Y};
	objects.yellowstars.position = (Vector2){3650 * SCALE_X, 100 * SCALE_Y};

	return (objects);
}
