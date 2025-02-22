#include "todolist.hpp"

// class Task
todo::Task::Task(const std::string &desc, int section)
    : description(desc), section(section), is_finished(false),
      date(std::time(nullptr)) {}

todo::Task::~Task() {}

bool todo::Task::switch_status(void) {
  this->is_finished = !this->is_finished;
  return this->is_finished;
}

std::string todo::Task::get_desc(void) { return this->description; }

std::time_t todo::Task::get_date(void) { return this->date; }

int todo::Task::get_section(void) { return this->section; }

bool todo::Task::get_status(void) { return this->is_finished; }

// class Section
todo::Section::Section(const std::string &name) : name(name) {}

todo::Section::~Section() {}

std::string todo::Section::get_name(void) { return this->name; }

// class List
todo::List::List(Database *db) : db(db) {}

todo::List::~List() {}

void todo::List::add_task(const std::string &desc, int section_id) {
  std::string query = "INSERT INTO task (description, created_at, section, "
                      "status) VALUES ('" +
                      desc + "', " + std::to_string(std::time(nullptr)) + ", " +
                      std::to_string(section_id) + ", 0);";

  db->execute_query(query);
}

void todo::List::add_section(const std::string &name) {
  std::string query = "INSERT INTO section (name) VALUES ('" + name + "');";

  db->execute_query(query);
}

void todo::List::assign_task_to_section(int task_id, int section_id) {
  std::string query =
      "UPDATE tasks SET section_id = " + std::to_string(section_id) +
      " WHERE id = " + std::to_string(task_id) + ";";

  db->execute_query(query);
}

void todo::List::remove_task(int task_id) {
  std::string query =
      "DELETE FROM tasks WHERE id = " + std::to_string(task_id) + ";";

  db->execute_query(query);
}

void todo::List::remove_section(int section_id) {
  std::string query =
      "DELETE FROM sections WHERE id = " + std::to_string(section_id) + ";";

  db->execute_query(query);
}
