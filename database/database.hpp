#ifndef DATABASE_HPP

#define DATABASE_HPP

#include <iostream>
#include <memory>
#include <sqlite3.h>
#include <stdexcept>

class Database {
public:
  static std::unique_ptr<Database> &
  get_instance(const std::string &db_path = "todo-list.db");

  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;

  void execute_query(const std::string &);

  void close();

  ~Database();

private:
  std::unique_ptr<sqlite3, decltype(&sqlite3_close)> conn;
  static std::unique_ptr<Database> instance;

  explicit Database(const std::string &);
  void create_tables();
};

#endif // !DATABASE_HPP
