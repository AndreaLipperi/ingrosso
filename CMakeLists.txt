cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 14)

add_executable(ingrosso_online main.cpp utenti.h clienti.h fornitori.h magazzino.h carrello.h prodotti.h categorie.h utenti.cpp clienti.cpp fornitori.cpp magazzino.cpp carrello.cpp prodotti.cpp categorie.cpp)
