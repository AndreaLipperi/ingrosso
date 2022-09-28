cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 14)

add_executable(ingrosso_online main.cpp utenti.h customers.h fornitori.h warehouse.h favourites.h prodotti.h categories.h utenti.cpp customers.cpp fornitori.cpp warehouse.cpp favourites.cpp prodotti.cpp categories.cpp)
