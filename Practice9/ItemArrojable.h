//
// Created by Galaxyraul on 03/05/2022.
//

#ifndef PRUEBA_ITEMARROJABLE_H
#define PRUEBA_ITEMARROJABLE_H
#include "Item.h"

class ItemArrojable:public Item{
public:
    virtual float lanzar()=0;

    virtual ~ItemArrojable()=default;
};
#endif //PRUEBA_ITEMARROJABLE_H
