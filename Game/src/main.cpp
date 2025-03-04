#define OLC_PGE_APPLICATION
#include "ewublaster.h"


int main() {
	EwuBlaster game;
	if (game.Construct(256, 210, 4, 4))
		game.Start();
	return 0;
}
