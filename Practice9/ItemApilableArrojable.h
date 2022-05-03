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
    float damage = 0;
public:
    void std::string getDescription() override;
};


#endif //PRUEBA_ITEMAPILABLEARROJABLE_H
