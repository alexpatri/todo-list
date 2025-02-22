#include "database.hpp"

std::unique_ptr<Database> Database::instance = nullptr;

std::unique_ptr<Database> &Database::get_instance(const std::string &db_path) {
  if (!instance) {
    instance = std::unique_ptr<Database>(new Database(db_path));
  }
  return instance;
}

Database::Database(const std::string &db_path) : conn(nullptr, sqlite3_close) {
  sqlite3 *raw_conn = nullptr;
  if (sqlite3_open(db_path.c_str(), &raw_conn) != SQLITE_OK) {
    throw std::runtime_error("Failed to open database");
  }
  conn.reset(raw_conn);

  create_tables();
}

Database::~Database() { close(); }

void Database::create_tables() {
  const char *query = R"(
        CREATE TABLE IF NOT EXISTS section (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL
        );

        CREATE TABLE IF NOT EXISTS task (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            description TEXT,
            created_at DATE NOT NULL,
            section INTEGER,
            status INTEGER,
            FOREIGN KEY (section) REFERENCES section(id)
        );
        )";

  execute_query(query);
}

void Database::execute_query(const std::string &q) {
  char *err_msg = nullptr;
  if (sqlite3_exec(conn.get(), q.c_str(), nullptr, nullptr, &err_msg) !=
      SQLITE_OK) {
    std::string error = "Erro executing query: " + std::string(err_msg);
    sqlite3_free(err_msg);
    throw std::runtime_error(error);
  }
}

void Database::close() { conn.reset(); }
