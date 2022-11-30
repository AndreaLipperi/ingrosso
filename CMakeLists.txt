cmake_minimum_required(VERSION 3.23)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 11)


find_package(wxWidgets REQUIRED net gl core base media)
#find_package(SQLite3 REQUIRED net gl core base media)
include(${wxWidgets_USE_FILE})


add_executable(ingrosso_online main.cpp users.h cart.h favourites.h subcategories.h categories.h users.cpp cart.cpp favourites.cpp subcategories.cpp categories.cpp usersMethods.h usersMethods.cpp categoriesMethods.h categoriesMethods.cpp subcategoriesMethods.h subcategoriesMethods.cpp cartMethods.cpp cartMethods.h favouritesMethods.cpp favouritesMethods.h orders.cpp orders.h ordersMethods.cpp ordersMethods.h store.cpp store.h storeMethods.cpp storeMethods.h Enter.h Enter.cpp Menu.h Menu.cpp MyApp.cpp MyApp.h RegisterFrame.cpp RegisterFrame.h SelectFrame.h SelectFrame.cpp ClientFrame.cpp ClientFrame.h ProvidersFrame.cpp ProvidersFrame.h)

target_link_libraries(ingrosso_online ${wxWidgets_LIBRARIES})
#target_link_libraries(ingrosso_online ${SQLite3_LIBRARIES})

