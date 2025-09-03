#ifndef Transform
#define Transform

#include "../component.hpp"
#include "../physics.h"

struct Transform : public Component {
public:
  Physics::Vector2f position;
  Physics::Vector2f velocity;

  int speed = 3;
  int gravity = 4;
  bool applyGravity = false;

	Transform() {
		position.Zero();
	}
	Transform(int scale) {
		position.Zero();
		this->scale = scale;
	}
	Transform(float x, float y) {
		position.x = x;
		position.y = y;
	}
	Transform(float x, float y, int scale) {
		position.x = x;
		position.y = y;
		this->scale = scale;
	}

  void init() override {
    velocity.Zero();
  }
}

#endif // Transform
