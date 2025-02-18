#include "database/database.hpp"
#include <iostream>

int main() {
  std::unique_ptr<db::Database> db = db::new_database("todo-list.db");

  return 0;
}
