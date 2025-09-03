#ifndef PHYSICS
#define PHYSICS

#include <math.h>
#include <iostream>

class Physics {
public:
	class Vector2f {
	public:
		int x, y;
		Vector2f() : x(0), y(0) {};
		Vector2f(int x, int y) : x(x), y(y) {}

		Vector2f& Add(const Vector2f& vec) {
      this->x += vec.x;
      this->y += vec.y;

      return *this;
    };
		Vector2f& Subtract(const Vector2f& vec) {
      this->x -= vec.x;
      this->y -= vec.y;

      return *this;
    };
		Vector2f& Multiply(const Vector2f& vec) {
      this->x *= vec.x;
      this->y *= vec.y;

      return *this;
    };
		Vector2f& Divide(const Vector2f& vec) {
      this->x /= vec.x;
      this->y /= vec.y;

      return *This;
    };

		friend Vector2f& operator+(Vector2f& v1, const Vector2f& v2) { return v1.Add(v2); }
		friend Vector2f& operator-(Vector2f& v1, const Vector2f& v2) { return v1.Subtract(v2); }
		friend Vector2f& operator*(Vector2f& v1, const Vector2f& v2) { return v1.Multiply(v2); }
		friend Vector2f& operator/(Vector2f& v1, const Vector2f& v2) { return v1.Divide(v2); }

    Vector2f& operator+=(const Vector2f& vec) { return this->Add(vec); }
    Vector2f& operator-=(const Vector2f& vec) { return this->Subtract(vec); }
    Vector2f& operator*=(const Vector2f& vec) { return this->Multiply(vec); }
    Vector2f& operator/=(const Vector2f& vec) { return this->Divide(vec); }
		// Scalar
		Vector2f& operator*(const int& i) {
      this->x *= i;
      this->y *= i;

      return *this;
    };
		Vector2f& Zero() {
      this->x = 0;
      this->y = 0;

      return *this;
    };

		double mag() { return sqrt((this->x + this->y)); };

		friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vec) {
      stream << "(" << vec.x << ", " << vec.y << ")";
      return stream;
    };
	private:
	};
};

#endif // PHYSICS
