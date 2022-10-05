#include "Employee.h"

Employee::Employee() {}
Employee::~Employee() {}
void Employee::setPost(string post) { this->post = post; }
void Employee::setInitials(string init) { initials = init; }
string Employee::getPost() { return post; }
string Employee::getInitials() { return initials; }