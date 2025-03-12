#pragma once

#include <chrono>
#include <random>

#include "olcPixelGameEngine.h"

olc::vi2d getMonitorSize();

template <typename _IntType = int>
_IntType randInt(_IntType p_min, _IntType p_max);

template <typename _RealType = double>
_RealType randReal(_RealType p_min, _RealType p_max);
