cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)


find_package(wxWidgets REQUIRED net gl core base media)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES users.h cart.h favourites.h subcategories.h categories.h users.cpp cart.cpp favourites.cpp subcategories.cpp categories.cpp usersMethods.h usersMethods.cpp categoriesMethods.h categoriesMethods.cpp subcategoriesMethods.h subcategoriesMethods.cpp cartMethods.cpp cartMethods.h favouritesMethods.cpp favouritesMethods.h orders.cpp orders.h ordersMethods.cpp ordersMethods.h store.cpp store.h storeMethods.cpp storeMethods.h)

add_executable(ingrosso_online main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(ingrosso_online core)
target_link_libraries(ingrosso_online ${wxWidgets_LIBRARIES})
