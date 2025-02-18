#include <iostream>
#include <memory>
#include <sqlite3.h>

class Database {
public:
  static std::unique_ptr<Database> &
  get_instance(const std::string &db_path = "database.db");

  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;

  ~Database();

private:
  std::unique_ptr<sqlite3, decltype(&sqlite3_close)> conn;
  static std::unique_ptr<Database> instance;

  explicit Database(const std::string &);
  void create_tables();
  void close();
};
