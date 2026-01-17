#ifndef INCLUDE_MATH_CONSTANTS_H_
#define INCLUDE_MATH_CONSTANTS_H_

#define _USE_MATH_DEFINES
#include <cmath>

namespace math::constants {
/**
 * @brief convert degrees to radians
 *
 * @param ang the angle expressed in degrees
 * @return the angle expreesed in radians
 */
constexpr double deg2rad(double ang) { return ang * (M_PI / 180.0); }
}  // namespace math::constants

#endif  // INCLUDE_MATH_CONSTANTS_H_
