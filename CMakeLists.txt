cmake_minimum_required(VERSION 3.21)
project(ingr_online)

set(CMAKE_CXX_STANDARD 14)

add_executable(ingr_online main.cpp utenti.h clienti.h fornitori.h magazzino.h carrello.h prodotti.h categorie.h)
