cmake_minimum_required(VERSION 3.21)
project(ingrosso_online)

set(CMAKE_CXX_STANDARD 11)


find_package(wxWidgets REQUIRED net gl core base media)
find_package(SQLite3 REQUIRED net gl core base media)
include(${wxWidgets_USE_FILE})


add_executable(ingrosso_online main.cpp users.h cart.h favourites.h products.h categories.h users.cpp cart.cpp favourites.cpp products.cpp categories.cpp tableUsers.h tableUsers.cpp tableCategories.h tableCategories.cpp tableProducts.h tableProducts.cpp tableCart.cpp tableCart.h tableFavourites.cpp tableFavourites.h orders.cpp orders.h tableOrders.cpp tableOrders.h store.cpp store.h tableStore.cpp tableStore.h)

target_link_libraries(ingrosso_online ${wxWidgets_LIBRARIES})
target_link_libraries(ingrosso_online ${SQLite3_LIBRARIES})

