#include "todolist.hpp"

// class Task
todo::Task::Task(const std::string &desc, int section = -1) {
  this->description = desc;
  this->section = section;
  this->is_finished = false;
  this->date = std::time(NULL);
}

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
todo::Section::Section(const std::string &name) { this->name = name; }

todo::Section::~Section() {}

std::string todo::Section::get_name(void) { return this->name; }

// class List
todo::List::List(Database *db) : db(db) {}

todo::List::~List() {}
