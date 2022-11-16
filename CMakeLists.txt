cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 11)


find_package(wxWidgets REQUIRED net gl core base media)
find_package(SQLite3 REQUIRED net gl core base media)
include(${wxWidgets_USE_FILE})


add_executable(ingrosso_online main.cpp users.h cart.h favourites.h products.h categories.h users.cpp cart.cpp favourites.cpp products.cpp categories.cpp usersMethods.h usersMethods.cpp categoriesMethods.h categoriesMethods.cpp productsMethods.h productsMethods.cpp cartMethods.cpp cartMethods.h favouritesMethods.cpp favouritesMethods.h orders.cpp orders.h ordersMethods.cpp ordersMethods.h store.cpp store.h storeMethods.cpp storeMethods.h)

target_link_libraries(ingrosso_online ${wxWidgets_LIBRARIES})
target_link_libraries(ingrosso_online ${SQLite3_LIBRARIES})

