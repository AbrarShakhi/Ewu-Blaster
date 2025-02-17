#define OLC_PGE_APPLICATION
#include "spaceblaster.h"


int main() {
	SpaceBlaster game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
}
