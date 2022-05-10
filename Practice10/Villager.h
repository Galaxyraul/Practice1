//
// Created by Galaxyraul on 10/05/2022.
//

#ifndef PRUEBA_VILLAGER_H
#define PRUEBA_VILLAGER_H
#include "Inventario.h"
#include "Item.h"


class Villager {
private:
    Inventario* _inventory= nullptr;
    int _emeralds = 64;
public:
    std::string sell(Item* item,int offer);

    std::string buy(Item* item,int value);

    int getEmeralds() const;

    int getNumObjects() const;

    Item& consulta(int cual);


};


#endif //PRUEBA_VILLAGER_H
