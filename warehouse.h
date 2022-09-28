//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_MAGAZZINO_H
#define INGR_ONLINE_MAGAZZINO_H

class Warehouse {
public:
    explicit Warehouse(int p_av, int pr);


private:
    int product_availability;
    int price;

};


#endif //INGR_ONLINE_MAGAZZINO_H
