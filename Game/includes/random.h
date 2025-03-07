#include <chrono>
#include <random>


static inline std::default_random_engine default_engine;
static inline auto clock_seed =
    std::chrono::steady_clock::now().time_since_epoch().count();
static inline std::random_device rd_seed;
std::mt19937 mersenne_twister_engine((uint32_t)clock_seed);

template <typename _IntType = int>
inline _IntType randInt(_IntType a, _IntType b) {
	return std::uniform_int_distribution<_IntType>(a,
	                                               b)(mersenne_twister_engine);
}

template <typename _RealType = double>
inline _RealType randReal(_RealType a, _RealType b) {
	return std::uniform_real_distribution<_RealType>(
	    a, b)(mersenne_twister_engine);
}
