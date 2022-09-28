cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 14)

add_executable(ingrosso_online main.cpp users.h customers.h providers.h cart.h favourites.h products.h categories.h users.cpp customers.cpp providers.cpp cart.cpp favourites.cpp products.cpp categories.cpp)
