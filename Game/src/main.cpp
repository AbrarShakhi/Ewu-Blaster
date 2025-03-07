#define OLC_PGE_APPLICATION
#include "ewublaster.h"

int main() {
	EwuBlaster game;

	if (game.gameStatus == olc::OK)
		game.Start();
	else
		return EXIT_FAILURE;
}
