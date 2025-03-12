#define OLC_PGE_APPLICATION
#include "game.h"


int main() {
	Game game;

	if (game.gameStatus != olc::OK)
		return EXIT_FAILURE;
	game.Start();
}
