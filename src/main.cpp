#include <iostream>

#include "ecs.hpp"
#include "components/transform.hpp"

namespace Game {
  ECS ecs;
  Entity* player = nullptr;
  Entity* enemy = nullptr;
}

void eventHandler() {
  Game::ecs.eventHandler();

  // Simulate player pressing D (moving right)
  Transform* p_transform = Game::player->getComponent<Transform>();
  p_transform->velocity.x = 1;
}

void update() {
  Game::ecs.update();

  std::cout << "Player position: " << Game::player->getComponent<Transform>()->position << std::endl;
}

void render() {
  Game::ecs.render();
}

int main() {
  Game::player = &Game::ecs.addEntity();
  Game::enemy = &Game::ecs.addEntity();

  Game::player->addComponent<Transform>(1);
  Game::enemy->addComponent<Transform>(2);

  while (true) {
    eventHandler();
    update();
    render();
    sleep(1);
  }
}

