#include "utils/helper.h"


olc::vi2d getMonitorSize() { return {256, 240}; }

inline int64_t generateSeed() {
	return std::chrono::steady_clock::now().time_since_epoch().count();
}

inline std::mt19937 useMtEngine() {
	std::random_device rd_seed;
	std::mt19937 mersenne_twister_engine((uint32_t)generateSeed());
	return mersenne_twister_engine;
}

template <typename _IntType>
_IntType randInt(_IntType a, _IntType b) {
	return std::uniform_int_distribution<_IntType>(a, b)(useMtEngine());
}

template <typename _RealType>
_RealType randReal(_RealType a, _RealType b) {
	return std::uniform_real_distribution<_RealType>(a, b)(useMtEngine());
}
