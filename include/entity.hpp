#ifndef ENTITY
#define ENTITY

#include <stdint.h>
#include <vector>
#include "component.hpp"

class Entity {
public:
  Entity() : id(0) {}
  Entity(std::uint32_t id) : id(id) {}

  void eventHandler();
  void update();
  void render();

  bool operator==(Entity& other) { return this->id == other.id; }
  bool operator!=(Entity& other) { return this->id != other.id; }
  operator std::uint32_t() const { return this->id; }

  std::uint32_t getID() { return this->id; }

private:
  std::uint32_t id;

  std::vector<std::unique_ptr<Component>> components;
};

#endif // ENTITY

