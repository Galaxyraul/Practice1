//
// Created by Galaxyraul on 03/05/2022.
//

#include "ItemApilableArrojable.h"
#include <iostream>


ItemApilableArrojable::ItemApilableArrojable(int numberOfElements,int damage) : ItemApilable(numberOfElements),_damage(damage) {}

ItemApilableArrojable::ItemApilableArrojable() {}

ItemApilableArrojable::~ItemApilableArrojable() {

}

float ItemApilableArrojable::getDamage() const {
    return _damage;
}

void ItemApilableArrojable::setDamage(float damage) {
    _damage = damage;
}

