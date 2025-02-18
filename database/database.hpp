#include <iostream>
#include <memory>
#include <sqlite3.h>

namespace db {
class Database {
public:
  explicit Database(const std::string &);
  ~Database();

private:
  std::unique_ptr<sqlite3, decltype(&sqlite3_close)> conn;

  void create_tables();
  void close();
};

std::unique_ptr<Database> new_database(const std::string &);
} // namespace db
