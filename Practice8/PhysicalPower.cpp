//
// Created by cocol on 16/04/2022.
//

#include "PhysicalPower.h"

PhysicalPower::PhysicalPower() {}

PhysicalPower::PhysicalPower(const std::string &name, const std::string &description, const std::string &effectiveOn,
                             float destructiveCapacity) : Power(name, description, effectiveOn, destructiveCapacity) {}

PhysicalPower::PhysicalPower(const Power &orig) : Power(orig) {}

PhysicalPower &PhysicalPower::operator=(const PhysicalPower &orig) {
    if(this != &orig){
        this->operator=(orig);
    }
    return *this;
}
