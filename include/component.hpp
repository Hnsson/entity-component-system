#ifndef COMPONENT
#define COMPONENT

class Entity;

class Component {
public:
  virtual ~Component() = default;

  virtual void init() = 0;
  virtual void eventHandler();
  virtual void update();
  virtual void render();
private:
  Entity* entity;
};

#endif // COMPONENT

