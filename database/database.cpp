#include "database.hpp"
#include <iostream>
#include <stdexcept>

db::Database::Database(const std::string &db_path)
    : conn(nullptr, sqlite3_close) {
  sqlite3 *raw_conn = nullptr;
  if (sqlite3_open(db_path.c_str(), &raw_conn) != SQLITE_OK) {
    throw std::runtime_error("Failed to open database");
  }
  conn.reset(raw_conn);

  create_tables();
}

db::Database::~Database() { close(); }

void db::Database::create_tables() {
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
  if (sqlite3_exec(conn.get(), query, nullptr, nullptr, &errMsg) != SQLITE_OK) {
    std::string error = "Error creating tables: " + std::string(errMsg);
    sqlite3_free(errMsg);
    throw std::runtime_error(error);
  }
}

void db::Database::close() { conn.reset(); }

std::unique_ptr<db::Database> db::new_database(const std::string &db_path) {
  try {
    return std::make_unique<Database>(db_path);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return nullptr;
  }
}
