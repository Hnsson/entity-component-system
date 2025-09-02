# entity-component-system
The Library should include the following parts to complete the Entity Component System (ECS):

## Entity - The game object
* An entity (ID) is a container that represents something in the world containing components.
* On its own it's nothing more than an ID, no data or behavior. Its only meaning is it's components attached to it.

## Component - The data
* A small, reusable piece of code.
* Mixing multiple components creates complex game objects without inheritance hierarchies, just flat relationships.
* Example components:
  - `Transform` - containing position, rotation, ...
  - `Renderable` - what is looks like being rendered.

## System - The behavior
* Where the logic lives. It operates over all entities, reading component data, updating it, as well as creating / deleting.
* Example systems:
  - `Movement system` - looks for `Transform` and update each frame.
  - `Render system` - look for `Transform` and `Renderable` and draws on screen.
