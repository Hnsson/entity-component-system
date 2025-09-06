#include <assert.h>
#include <stdio.h>
#include "ecs.hpp"
#include "entity.hpp"
#include "components/transform.hpp"

// Because I can only add one unique component at a time
// else it will return the same, I will create different components:
#define GEN_DUMMY(N) \
  struct Dummy##N : public Component {}; \
  e2.addComponent<Dummy##N>();

void test_entity_creation(Entity& e1, Entity& e2) {
  assert(e1.getID() == 0);
  assert(e2.getID() == 1);
  assert(e1 != e2);
  assert(e1 == e1);
}

void test_component_creation(Entity& e1) {
  assert(e1.hasComponent<Transform>() == true);

  Transform* t1_ptr = e1.getComponent<Transform>();
  assert(t1_ptr != nullptr);
  assert(t1_ptr->scale == 2);
  assert(t1_ptr->position.x == 5.0f);
  assert(t1_ptr->position.y == 10.0f);
}

void test_duplicate_component(Entity& e1, Transform& t1) {
  Transform& t1_again = e1.addComponent<Transform>(99.0f, 99.0f);
  assert(&t1 == &t1_again); // Should be the same (can only have one)
  assert(t1.position.x == 5.0f);
}

struct DummyComponent : public Component {};

void test_exceed_maximum_components(Entity& e2) {
  try {
    GEN_DUMMY(0); GEN_DUMMY(1); GEN_DUMMY(2); GEN_DUMMY(3);
    GEN_DUMMY(4); GEN_DUMMY(5); GEN_DUMMY(6); GEN_DUMMY(7);
    GEN_DUMMY(8); GEN_DUMMY(9); GEN_DUMMY(10); GEN_DUMMY(11);
    GEN_DUMMY(12); GEN_DUMMY(13); GEN_DUMMY(14); GEN_DUMMY(15);
    GEN_DUMMY(16); GEN_DUMMY(17); GEN_DUMMY(18); GEN_DUMMY(19);
    GEN_DUMMY(20); GEN_DUMMY(21); GEN_DUMMY(22); GEN_DUMMY(23);
    GEN_DUMMY(24); GEN_DUMMY(25); GEN_DUMMY(26); GEN_DUMMY(27);
    GEN_DUMMY(28); GEN_DUMMY(29); GEN_DUMMY(30); GEN_DUMMY(31);
    assert(false && "Should have thrown exception when exceeding max (32) components");
  } catch (const std::runtime_error& ex) {
    std::cout << "Successfully catched exception when exceeding max components added to an entity" << std::endl;
  }
}

int main() {
  printf("Running tests...\n");

  printf("=========== CAPTURED OUTPUT ===========\n");
  ECS ecs;
  Entity& e1 = ecs.addEntity();
  Entity& e2 = ecs.addEntity();
  Transform& t1 = e1.addComponent<Transform>(5.0f, 10.0f, 2);

  // Test 1: Entity creation
  test_entity_creation(e1, e2);

  // Test 2: Component creation
  test_component_creation(e1);

  // Test 3: Component duplication
  test_duplicate_component(e1, t1);

  // Test 4: Excdeed maximum components
  test_exceed_maximum_components(e2);

  printf("=======================================\n");

  printf("All tests passed!\n");
  return 0;
}

