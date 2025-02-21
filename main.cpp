#include "database/database.hpp"
#include "todolist/todolist.hpp"

#include <cstdlib>
#include <string>

int main() {
  std::string home{std::getenv("HOME")};
  std::string db_path{home.append("/todo-list.db")};

  auto &db{Database::get_instance(db_path)};

  todo::List list(db.get());

  return 0;
}
