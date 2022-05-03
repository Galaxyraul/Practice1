//
// Created by Galaxyraul on 03/05/2022.
//

#ifndef PRUEBA_ITEMAPILABLEARROJABLE_H
#define PRUEBA_ITEMAPILABLEARROJABLE_H
#include "ItemArrojable.h"
#include "ItemApilable.h"
#include <string>

class ItemApilableArrojable: public ItemApilable,public ItemArrojable{
private:
    float _damage = 0;
public:
     virtual std::string getDescription() = 0;

     float lanzar() override;
};


#endif //PRUEBA_ITEMAPILABLEARROJABLE_H
