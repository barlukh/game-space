#include "config.h"

void textures_unload(Graphics objects)
{
	UnloadTexture(objects.blueplanet.texture);
	UnloadTexture(objects.earth.texture);
	UnloadTexture(objects.purpleplanet.texture);
	UnloadTexture(objects.redplanet.texture);
	UnloadTexture(objects.rocketwhite.texture);
	UnloadTexture(objects.satellite.texture);
	UnloadTexture(objects.saturn.texture);
	UnloadTexture(objects.sun.texture);
	UnloadTexture(objects.title.texture);
	UnloadTexture(objects.whiteshootingstar.texture);
	UnloadTexture(objects.whitestar.texture);
	UnloadTexture(objects.whitestars1.texture);
	UnloadTexture(objects.whitestars2.texture);
	UnloadTexture(objects.yellowhalfmoon.texture);
	UnloadTexture(objects.yellowshootingstar.texture);
	UnloadTexture(objects.yellowstars.texture);
}
