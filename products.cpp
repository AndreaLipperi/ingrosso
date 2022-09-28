//
// Created by Matilde Tarchi on 02/08/22.
//

#include "products.h"
#include "categories.h"


Products::Products(char n, char desc, char c_n) : Categories(c_n), name(n), desc(desc)  {
}