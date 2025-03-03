#include <chrono>
#include <cstdint>
#include <random>

std::default_random_engine default_engine;

auto clock_seed = std::chrono::steady_clock::now().time_since_epoch().count();
std::random_device rd_seed;
std::mt19937 mersenne_twister_engine((uint32_t)clock_seed);

int randint(int a, int b) {
	return std::uniform_int_distribution<int>(a, b)(mersenne_twister_engine);
}

float randfloat(float a, float b) {
	return std::uniform_real_distribution<float>(a, b)(mersenne_twister_engine);
}