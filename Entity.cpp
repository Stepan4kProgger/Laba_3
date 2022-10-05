#include "Entity.h"
using namespace std;

Entity::Entity() { cout << "Entity constr\n"; }
Entity::~Entity() { cout << "Entity destr\n"; }
void Entity::setName(string inp) { name = inp; }
void Entity::setFace(bool state) { is_juristic = state; }
string Entity::getName() { return name; }
bool Entity::getFace() { return is_juristic; }