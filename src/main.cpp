#include <iostream>

#include "ecs.hpp"
#include "components/transform.hpp"

int main() {
  ECS ecs;

  Entity& player = ecs.addEntity();
  Entity& enemy = ecs.addEntity();

  player.addComponent<Transform>(1);
  std::cout << "Enemy Has component? " << enemy.hasComponent<Transform>() << std::endl;
  enemy.addComponent<Transform>(2);
  std::cout << "Has component? " << player.hasComponent<Transform>() << std::endl;
  std::cout << "Has component? " << player.hasComponent<Transform>() << std::endl;
  std::cout << "Has component? " << player.hasComponent<Transform>() << std::endl;
  std::cout << "Enemy Has component? " << player.hasComponent<Transform>() << std::endl;

  Transform* transform = player.getComponent<Transform>();
  Transform* transform_enemy = enemy.getComponent<Transform>();

  std::cout << "Player transform: " << transform->scale << std::endl;
  player.addComponent<Transform>(2);
  std::cout << "Player transform: " << transform->scale << std::endl;
  std::cout << "Enemy transform: " << transform_enemy->scale << std::endl;

  std::cout << "Hello from main!" << std::endl;
  return 0;
}

