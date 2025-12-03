#ifndef ECS_H
#define ECS_H

#include <bitset>
#include <vector>

// Signature
const unsigned int MAX_COMPONENTS = 32;
// Using bitset (1s and 0s) to keep track of which compoents an entity has
typedef std::bitset<MAX_COMPONENTS> Signature;

class Component {};

class Entity {
private:
  int id;

public:
  // in C++ the id(id) is { this.id = id }
  Entity(int id) : id(id) {};
  int GetId() const;
};

class System {
private:
  Signature componentSignature;
  std::vector<Entity> entities;

public:
  System() = default;
  ~System() = default;

  void AddEntity(Entity entity);
  void RemoveEntity(Entity entity);
  std::vector<Entity> GetEntities() const;
  Signature &GetComponentSignature() const;
};
class Registry {};

#endif
