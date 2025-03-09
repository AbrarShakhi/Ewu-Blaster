#pragma once

#include <chrono>
#include <random>

#include "olcPixelGameEngine.h"

olc::vi2d getMonitorSize();

template <typename _IntType = int>
_IntType randInt(_IntType a, _IntType b);

template <typename _RealType = double>
_RealType randReal(_RealType a, _RealType b);
