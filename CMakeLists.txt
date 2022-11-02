cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 14)
find_package(SQLite3 REQUIRED net gl core base)
#include(${SQLite3_LIBRARIES})
add_executable(ingrosso_online main.cpp users.h customers.h providers.h cart.h favourites.h products.h categories.h users.cpp customers.cpp providers.cpp cart.cpp favourites.cpp products.cpp categories.cpp)
target_link_libraries(ingrosso_online ${SQLite3_LIBRARIES})