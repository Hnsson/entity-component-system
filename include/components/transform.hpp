#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include "../component.hpp"
#include "../physics.hpp"

class Transform : public Component {
public:
  Physics::Vector2f position;
  Physics::Vector2f velocity;

  int speed = 3;
  int gravity = 4;
  int scale = 1;
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
  ~Transform() {}

  void init() override {
    velocity.Zero();
  }

  void eventHandler() override {}
  void update() override {}
  void render() override {}
};

#endif // TRANSFORM_COMPONENT
