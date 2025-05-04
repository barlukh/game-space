#include "config.h"

void textures_unload(Visuals space)
{
	UnloadTexture(space.blueplanet);
	UnloadTexture(space.earth);
	UnloadTexture(space.explosion);
	UnloadTexture(space.purpleplanet);
	UnloadTexture(space.redplanet);
	UnloadTexture(space.rocketwhite);
	UnloadTexture(space.satellite);
	UnloadTexture(space.saturn);
	UnloadTexture(space.sun);
	UnloadTexture(space.text);
	UnloadTexture(space.whiteshootingstar);
	UnloadTexture(space.whitestar);
	UnloadTexture(space.whitestars1);
	UnloadTexture(space.whitestars2);
	UnloadTexture(space.yellowhalfmoon);
	UnloadTexture(space.yellowshootingstar);
	UnloadTexture(space.yellowstars);
}
