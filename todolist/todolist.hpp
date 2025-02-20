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

private:
  std::string decription;
  std::time_t date;
  bool is_finished;
  int section;
};

// TODO: Criar a class Section
//
// TODO: Criar a class List
} // namespace todo

#endif // !TODOLIST_HPP
