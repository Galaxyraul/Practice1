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

     virtual float lanzar() = 0;

    float getDamage() const;

    void setDamage(float damage);

    ItemApilableArrojable(int numberOfElements,int damage);

    ItemApilableArrojable();

    virtual ~ItemApilableArrojable();
};


#endif //PRUEBA_ITEMAPILABLEARROJABLE_H
