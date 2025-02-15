#include "database.hpp"

Database::Database(const std::string &dbName) {
  if (sqlite3_open(dbName.c_str(), &conn) != SQLITE_OK) {
    throw std::runtime_error("Failed to open database: " +
                             std::string(sqlite3_errmsg(conn)));
  }

  createTables();
}

Database::~Database() { close(); }

void Database::createTables() {
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
            FOREIGN KEY (section) REFERENCES section(id)
        );
        )";

  char *errMsg = nullptr;
  if (sqlite3_exec(conn, query, nullptr, nullptr, &errMsg) != SQLITE_OK) {
    std::string error = "Error creating tables: " + std::string(errMsg);
    sqlite3_free(errMsg);
    throw std::runtime_error(error);
  }
}

void Database::close() {
  if (conn) {
    sqlite3_close(conn);
    conn = nullptr;
  }
}
