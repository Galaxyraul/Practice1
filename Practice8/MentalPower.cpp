//
// Created by cocol on 16/04/2022.
//

#include "MentalPower.h"
#include "string"
#include <iostream>

MentalPower::MentalPower():Power() {}

MentalPower::MentalPower(const std::string &name, const std::string &description, const std::string &effectiveOn,
                         float destructiveCapacity) : Power(name, description, effectiveOn, destructiveCapacity)
                         {}

MentalPower::MentalPower(const Power &orig) : Power(orig) {}

MentalPower &MentalPower::operator=(const MentalPower &orig) {
    if(this != &orig){
        this->operator=(orig);
    }
    return *this;
}

float MentalPower::getLucidity() const {
    return _lucidity;
}

void MentalPower::setLucidity(float lucidity) {
    if(lucidity < 0 || lucidity > 1){
        throw std::invalid_argument("MentalPower.cpp::setLucidity:The value is not suitable");
    }
    _lucidity = lucidity;
}

float MentalPower::getDestructiveCapacity() const {
    return Power::getDestructiveCapacity()*_lucidity;
}
