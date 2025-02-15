#include <iostream>
#include <memory>
#include <sqlite3.h>

class Database {
public:
  explicit Database(const std::string &);
  ~Database();

private:
  sqlite3 *conn = nullptr;

  void createTables();
  void close();
};
