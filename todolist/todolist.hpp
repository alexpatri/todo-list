#ifndef TODOLIST_HPP

#define TODOLIST_HPP

#include "../database/database.hpp"

#include <ctime>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace todo {
class Task {
public:
  Task(const std::string &, int section = -1);
  ~Task();

  bool switch_status(void);

  std::string get_desc(void);
  std::time_t get_date(void);
  int get_section(void);
  bool get_status(void);

private:
  std::string description;
  std::time_t date;
  bool is_finished;
  int section;
};

class Section {
public:
  Section(const std::string &);
  ~Section();

  std::string get_name(void);

private:
  std::string name;
};

// TODO: Criar a class List
class List {
public:
  List(Database *);
  ~List();

  void add_task(const std::string &desc, int section_id = -1);
  void add_section(const std::string &name);
  void assign_task_to_section(int task_id, int section_id);
  void remove_task(int task_id);
  void remove_section(int section_id);
  void toggle_task_status(int task_id);

  std::vector<Task> get_all_tasks();
  std::vector<Task> get_tasks_by_section(int section_id);

private:
  std::unordered_map<int, Task> tasks;
  std::unordered_map<int, Section> sections;
  Database *db;

  void load_from_db();
};
} // namespace todo

#endif // !TODOLIST_HPP
