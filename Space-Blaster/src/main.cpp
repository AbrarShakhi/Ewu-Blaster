#define OLC_PGE_APPLICATION
#include "spaceblaster.h"


int main() {
	SpaceBlaster game;
	if (game.Construct(256, 210, 4, 4))
		game.Start();
	return 0;
}
