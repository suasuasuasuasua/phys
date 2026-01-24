#include <math/linalg/vector.h>

#include <cmath>
#include <sstream>
#include <stdexcept>

namespace math::linalg {
Vector2 Vector2::operator+(const Vector2 &other) const {
  return {.x = x + other.x, .y = y + other.y};
}
Vector2 Vector2::operator-(const Vector2 &other) const {
  return {.x = x - other.x, .y = y - other.y};
}
Vector2 Vector2::operator*(double scalar) const {
  return {.x = x * scalar, .y = y * scalar};
}
Vector2 Vector2::operator/(double scalar) const {
  if (scalar == 0.0) {
    throw std::invalid_argument("Vector division must not be by zero");
  }
  return {.x = x / scalar, .y = y / scalar};
}
Vector2 &Vector2::operator+=(const Vector2 &other) {
  x += other.x;
  y += other.y;
  return *this;
}
Vector2 &Vector2::operator-=(const Vector2 &other) {
  x -= other.x;
  y -= other.y;
  return *this;
}
Vector2 &Vector2::operator*=(double scalar) {
  x *= scalar;
  y *= scalar;
  return *this;
}
Vector2 &Vector2::operator/=(double scalar) {
  if (scalar == 0.0) {
    throw std::invalid_argument("Vector division must not be by zero");
  }
  x /= scalar;
  y /= scalar;
  return *this;
}
Vector2 Vector2::operator-() const { return {.x = -x, .y = -y}; }
bool operator==(const Vector2 &lhs, const Vector2 &rhs) {
  return (lhs.x == rhs.x) and (lhs.y == rhs.y);
}
bool operator!=(const Vector2 &lhs, const Vector2 &rhs) {
  return (lhs.x != rhs.x) or (lhs.y != rhs.y);
}
Vector2 operator*(double scalar, const Vector2 &v) {
  return {.x = scalar * v.x, .y = scalar * v.y};
}
Vector2 operator/(double scalar, const Vector2 &v) {
  return {.x = scalar / v.x, .y = scalar / v.y};
}

std::string Vector2::to_string() {
  std::stringstream ss;
  ss << "{ " << x << ", " << y << " }";
  return ss.str();
}

double Vector2::mag() const {
  double magnitude = x * x + y * y;
  return magnitude;
}
Vector2 Vector2::unit() const {
  double magnitude = mag();
  return *this / magnitude;
}
double Vector2::angle() const {
  double ang = std::atan2(y, x);
  return ang;
}
Vector2 Vector2::from_mag_ang(double magnitude, double angle) {
  double x = magnitude * std::cos(angle);
  double y = magnitude * std::sin(angle);
  return {.x = x, .y = y};
}
}  // namespace math::linalg
