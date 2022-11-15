cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 11)


find_package(wxWidgets REQUIRED net gl core base media)
find_package(SQLite3 REQUIRED net gl core base media)
include(${wxWidgets_USE_FILE})


add_executable(ingrosso_online main.cpp users.h customers.h providers.h cart.h favourites.h products.h categories.h users.cpp customers.cpp providers.cpp cart.cpp favourites.cpp products.cpp categories.cpp tableUsersDB.h tableUsersDB.cpp)

target_link_libraries(ingrosso_online ${wxWidgets_LIBRARIES})
target_link_libraries(ingrosso_online ${SQLite3_LIBRARIES})

