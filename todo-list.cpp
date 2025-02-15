#include "database/database.hpp"
#include <iostream>

int main() {
  try {
    Database db("todo-list.db");
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
