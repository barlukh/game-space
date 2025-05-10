#include "config.h"

void objects_unload(Graphics *objects)
{
	// Enemies

	UnloadTexture(objects->enemy[0].tex);
	

	// Player

	UnoadTexture(objects->player.tex[0]);
	UnoadTexture(objects->player.tex[1]);
	

	// Static objects

	UnloadTexture(objects->blueplanet.tex);
	UnloadTexture(objects->earth.tex);
	UnloadTexture(objects->purpleplanet.tex);
	UnloadTexture(objects->redplanet.tex);
	UnloadTexture(objects->rocketwhite.tex);
	UnloadTexture(objects->satellite.tex);
	UnloadTexture(objects->saturn.tex);
	UnloadTexture(objects->sun.tex);
	UnloadTexture(objects->title.tex);
	UnloadTexture(objects->whiteshootingstar.tex);
	UnloadTexture(objects->whitestar.tex);
	UnloadTexture(objects->whitestars1.tex);
	UnloadTexture(objects->whitestars2.tex);
	UnloadTexture(objects->yellowhalfmoon.tex);
	UnloadTexture(objects->yellowshootingstar.tex);
	UnloadTexture(objects->yellowstars.tex);
}
