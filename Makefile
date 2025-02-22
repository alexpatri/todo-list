build:
	g++ -Werror -Wall main.cpp database/database.cpp todolist/todolist.cpp -lsqlite3
