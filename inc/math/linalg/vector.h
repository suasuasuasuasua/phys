#ifndef INCLUDE_LINALG_VECTOR_H_
#define INCLUDE_LINALG_VECTOR_H_

#include <string>

namespace math::linalg {
/**
 * @class Vector2
 * @brief an implementation for a 2D vector
 *
 */
class Vector2 {
 public:
  /**
   * @brief default contructor for a 2D vector
   *
   * @param x the x-component
   * @param y the y-component
   */
  Vector2(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

  Vector2 operator+(const Vector2 &other) const;
  Vector2 operator-(const Vector2 &other) const;
  Vector2 operator*(double scalar) const;
  Vector2 operator/(double scalar) const;
  Vector2 &operator+=(const Vector2 &other);
  Vector2 &operator-=(const Vector2 &other);
  Vector2 &operator*=(double scalar);
  Vector2 &operator/=(double scalar);
  Vector2 operator-() const;
  friend bool operator==(const Vector2 &lhs, const Vector2 &rhs);
  friend bool operator!=(const Vector2 &lhs, const Vector2 &rhs);
  friend Vector2 operator*(double f, const Vector2 &v);
  friend Vector2 operator/(double f, const Vector2 &v);

  /**
   * @brief represent the vector as a string
   */
  std::string to_string();

  [[nodiscard]] double x() const;
  void x(const double &x);
  [[nodiscard]] double y() const;
  void y(const double &y);

  /**
   * @brief calculate the magnitude of the vector
   *
   * @return the magnitude of the vector
   */
  [[nodiscard]] double mag() const;
  /**
   * @brief calculate the unit vector
   *
   * @return the unit vector
   */
  [[nodiscard]] Vector2 unit() const;
  /**
   * @brief get the angle of the vectork
   *
   * @return the angle of the vector
   */
  [[nodiscard]] double angle() const;
  /**
   * @brief construct a vector from some magnitude and angle
   *
   * @param magnitude the magnitude value
   * @param angle the angle value
   * @return the constructed vector
   */
  static Vector2 from_mag_ang(double magnitude, double angle);

 private:
  double x_{}, y_{};
};

Vector2 operator*(double f, const Vector2 &v);
Vector2 operator/(double f, const Vector2 &v);
bool operator==(const Vector2 &lhs, const Vector2 &rhs);
bool operator!=(const Vector2 &lhs, const Vector2 &rhs);
}  // namespace math::linalg

#endif  // INCLUDE_LINALG_VECTOR_H_
