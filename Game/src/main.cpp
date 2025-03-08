#define OLC_PGE_APPLICATION
#include "ewublaster.h"

int main() {
	EwuBlaster game;

	if (game.gameStatus != olc::OK)
		return EXIT_FAILURE;
	game.Start();
}
