#include "config.h"

Visuals textures_load(Visuals space)
{
	space.blueplanet = LoadTexture("graphics/blueplanet.png");
	space.earth = LoadTexture("graphics/earth.png");
	space.purpleplanet = LoadTexture("graphics/purpleplanet.png");
	space.redplanet = LoadTexture("graphics/redplanet.png");
	space.rocketwhite = LoadTexture("graphics/rocketwhite.png");
	space.satellite = LoadTexture("graphics/satellite.png");
	space.saturn = LoadTexture("graphics/saturn.png");
	space.sun = LoadTexture("graphics/sun.png");
	space.text = LoadTexture("graphics/text.png");
	space.whiteshootingstar = LoadTexture("graphics/whiteshootingstar.png");
	space.whitestar = LoadTexture("graphics/whitestar.png");
	space.whitestars1 = LoadTexture("graphics/whitestars1.png");
	space.whitestars2 = LoadTexture("graphics/whitestars2.png");
	space.yellowhalfmoon = LoadTexture("graphics/yellowhalfmoon.png");
	space.yellowshootingstar = LoadTexture("graphics/yellowshootingstar.png");
	space.yellowstars = LoadTexture("graphics/yellowstars.png");

	return (space);
}
