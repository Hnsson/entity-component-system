#ifndef ECS_HPP
#define ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "entity.hpp"

using entityID = std::uint32_t;

inline entityID createEntityID() {
  static entityID lastID = 0u;
  return lastID++;
}

class ECS {
public:
  void eventHandler() {
    for (auto& e : entities) e->eventHandler();
  }
  void update() {
    for (auto& e : entities) e->update();
  }
  void render() {
    for (auto& e : entities) e->render();
  }

  Entity& addEntity() {
    Entity* e = new Entity(createEntityID());
    std::unique_ptr<Entity> ptr{e};
    entities.emplace_back(std::move(ptr));
    std::cout << "Added entity (" << e->getID() << ")!"<< std::endl;
    return *e;
  }

private:
  std::vector<std::unique_ptr<Entity>> entities;
};

#endif // ECS_HPP

