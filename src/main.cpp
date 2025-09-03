#include <iostream>

#include "ecs.hpp"

int main() {
  ECS ecs;

  Entity& player = ecs.addEntity();
  Entity& player_2 = ecs.addEntity();

  std::cout << "Hello from main!" << std::endl;
  return 0;
}

