#ifndef COMPONENT
#define COMPONENT

class Entity;

class Component {
public:
  virtual ~Component() = default;

  // default empty to complete vtable
  virtual void init() {};
  virtual void eventHandler() {};
  virtual void update() {};
  virtual void render() {};

  Entity* entity;
};

#endif // COMPONENT

