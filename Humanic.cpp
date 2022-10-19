#include "Humanic.h"
using namespace std;

Entity::Entity() { cout << "Entity constr\n"; }
Entity::~Entity() { cout << "Entity destr\n"; }
void Entity::setName(string inp) { name = inp; }
void Entity::setFace(bool state) { is_juristic = state; }
string Entity::getName() { return name; }
bool Entity::getFace() { return is_juristic; }

Employee::Employee() {}
Employee::~Employee() {}
void Employee::setPost(string post) { this->post = post; }
void Employee::setInitials(string init) { initials = init; }
string Employee::getPost() { return post; }
string Employee::getInitials() { return initials; }