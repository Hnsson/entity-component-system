#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <typeinfo>
#include <stdint.h>
#include <vector>
#include <bitset>
#include "component.hpp"

using componentID = std::uint32_t;

inline componentID createComponentTypeID() {
  static componentID lastID = 0u;
  return lastID++;
}

// This get the type id using STATIC variable for each distinct T type.
// That's why it doesn't change for each call because it is the same for each distinct T.
template <typename T>
inline componentID getComponentTypeID() {
  static componentID typeID = createComponentTypeID();
  return typeID;
}

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
  // C++20 way of creating variadic template (using argument deduction)
  template <typename T> T& addComponent(const auto&... args) {
    // If one already exsits, just return the existing one
    if (hasComponent<T>()) return *getComponent<T>();

    T* component = new T(args...);
    component->entity = this;
    std::unique_ptr<Component> ptr{ component };
    components.emplace_back(std::move(ptr));

    componentID typeID = getComponentTypeID<T>();
    activeComponents.set(typeID);

    component->init();

    std::cout << "Added component (" << typeid(T).name() << ") to entity (" << this->id << ")!"<< std::endl;
    return *component;
  }

  template <typename T> bool hasComponent() {
    componentID typeID = getComponentTypeID<T>();
    return activeComponents.test(typeID);
  }

  template <typename T> T* getComponent() {
    for (auto& c : components) {
        // Are they of the same type?
        if (typeid(*c) == typeid(T)) {
            return static_cast<T*>(c.get());
        }
    }
    return nullptr;
  }
private:
  std::uint32_t id;
  // This had to be a static constexpr so that it belongs to class and at compile time (not to each instance)
  static constexpr std::uint32_t max_components = 32;

  std::vector<std::unique_ptr<Component>> components;
  std::bitset<max_components> activeComponents;
};

#endif // ENTITY

