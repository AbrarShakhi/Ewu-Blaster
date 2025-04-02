#include "utils/helper.h"


olc::vi2d getMonitorSize() {
	return {200, 200};
}

inline int64_t generateSeed() {
	return std::chrono::steady_clock::now().time_since_epoch().count();
}

inline std::mt19937 useMtEngine() {
	std::random_device rd_seed;
	std::mt19937 mersenne_twister_engine((uint32_t)generateSeed());
	return mersenne_twister_engine;
}

template <typename _IntType>
_IntType randInt(_IntType p_min, _IntType p_max) {
	return std::uniform_int_distribution<_IntType>(p_min, p_max)(useMtEngine());
}

template <typename _RealType>
_RealType randReal(_RealType p_min, _RealType p_max) {
	return std::uniform_real_distribution<_RealType>(p_min, p_max)(useMtEngine());
}
