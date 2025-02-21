#ifndef TODOLIST_HPP

#define TODOLIST_HPP

#include <ctime>
#include <string>

namespace todo {
// TODO: Criar a class Task
class Task {
public:
  Task(const std::string &, int);
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

// TODO: Criar a class Section
//
// TODO: Criar a class List
} // namespace todo

#endif // !TODOLIST_HPP
