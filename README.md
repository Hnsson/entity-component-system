# entity-component-system
This library implements an object-oriented ECS (Entity Component System) in C++.

## Entity - The game object
* An `Entity`is an object in the world that **owns components**.
* On its own, an entity has no behavior, but its attached components define its capabilities.
* Example:
```c++
ECS ecs;
Entity& player = ecs.addEntity();
// Future implementation:
player.addComponent<Transform>(0, 0);
```

## Component - Data + behavior
* Components are small classes that contain both data and methods (`init()`, `update()`, `render()`).
* Components can reference their owning entity to access other components.
* Example:
  - `Transform` - stores position, rotation, scale.
  - `Collider` - handles collision logic
  - `...`

## ECS - Managing entities and components (registry)
* The ECS class manages all entities and their components.
