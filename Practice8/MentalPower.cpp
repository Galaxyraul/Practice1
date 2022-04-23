//
// Created by cocol on 16/04/2022.
//

#include "MentalPower.h"
#include "string"
#include <iostream>
#include "sstream"

MentalPower::MentalPower():Power() {}

MentalPower::MentalPower(const std::string &name, const std::string &description, const std::string &effectiveOn,
                         float destructiveCapacity,float lucidity) : Power(name, description, effectiveOn, destructiveCapacity)
                         {
                             if(lucidity < 0 || lucidity > 1){
                                 throw std::invalid_argument("MentalPower.cpp::setLucidity:The value is not suitable");
                             }
                             _lucidity = lucidity;
                         }
//Preguntar si se puede modificar
MentalPower::MentalPower(const Power &orig) : Power(orig){}

MentalPower &MentalPower::operator=(const MentalPower &orig) {
    if(this != &orig){
        this->operator=(orig);
        _lucidity = orig._lucidity;
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

std::string MentalPower::toCSV() const {
    std::stringstream s;
    s << ";" << _lucidity;
    return Power::toCSV() + s.str() ;
}

void MentalPower::setDestructiveCapacity(float destructiveCapacity) {
    Power::setDestructiveCapacity(destructiveCapacity*_lucidity);
}
