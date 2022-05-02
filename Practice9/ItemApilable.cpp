//
// Created by cocol on 02/05/2022.
//

#include "ItemApilable.h"
#include <string>
#include <iostream>

int ItemApilable::getNumberOfPiledElements() {
    return _numberOfElements;
}

void ItemApilable::increaseStack(int amount) {
    if(_numberOfElements+amount> 64){
        _numberOfElements = 64;
        throw std::out_of_range("ItemApilable.cpp::increaseStack:You have an extra of elements which cannot be stacked");
    }
    _numberOfElements+=amount;

}

void ItemApilable::decreaseStack(int amount) {
    if(_numberOfElements-amount < 1){
        _numberOfElements = 1;
        throw std::out_of_range("ItemApilable.cpp::decreaseStack:You do not have enough items stacked to remove");
    }
    _numberOfElements-=amount;
}
