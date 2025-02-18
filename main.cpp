#include "database/database.hpp"

int main() {
  auto &db = Database::get_instance("todo-list.db");
  return 0;
}
