cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)
add_subdirectory(SQLiteCpp)


find_package(SQLite3 REQUIRED net gl core base media)
include_directories(${SQLite3_INCLUDE_DIRS})
include_directories(SQLiteCpp/include)
find_package(wxWidgets REQUIRED net gl core base media)
include(${wxWidgets_USE_FILE})


set(SOURCE_FILES users.h cart.h favourites.h subcategories.h categories.h users.cpp cart.cpp favourites.cpp subcategories.cpp categories.cpp usersMethods.h usersMethods.cpp categoriesMethods.h categoriesMethods.cpp subcategoriesMethods.h subcategoriesMethods.cpp cartMethods.cpp cartMethods.h favouritesMethods.cpp favouritesMethods.h orders.cpp orders.h ordersMethods.cpp ordersMethods.h store.cpp store.h storeMethods.cpp storeMethods.h ClientFrame.cpp ClientFrame.h Enter.cpp Enter.h Menu.cpp Menu.h MyApp.cpp MyApp.h NewProductsFrame.cpp NewProductsFrame.h ProvidersFrame.cpp ProvidersFrame.h RegisterFrame.cpp RegisterFrame.h SelectFrame.cpp SelectFrame.h)

add_executable(ingrosso_online main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ingrosso_online core)
target_link_libraries(ingrosso_online SQLiteCpp sqlite3)
target_include_directories(ingrosso_online PRIVATE SQLiteCpp/include)
target_link_libraries(ingrosso_online ${wxWidgets_LIBRARIES})