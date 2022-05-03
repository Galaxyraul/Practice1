//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_ITEMAPILABLE_H
#define PRUEBA_ITEMAPILABLE_H
#include "Item.h"

class ItemApilable: public Item{
private:
    int _numberOfElements = 1;
public:
    int getNumberOfPiledElements();

    ItemApilable();

    ItemApilable(int numberOfElements);

    virtual std::string getDescription() = 0;

    void increaseStack (int amount);

    void decreaseStack (int amount);

    virtual ~ItemApilable();


};


#endif //PRUEBA_ITEMAPILABLE_H
