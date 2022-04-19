//
// Created by cocol on 16/04/2022.
//

#include "MentalPower.h"

MentalPower::MentalPower():Power() {}

MentalPower::MentalPower(const std::string &name, const std::string &description, const std::string &effectiveOn,
                         float destructiveCapacity,bool inhibited) : Power(name, description, effectiveOn, destructiveCapacity,inhibited)
                         {}

MentalPower::MentalPower(const Power &orig) : Power(orig) {}

MentalPower &MentalPower::operator=(const MentalPower &orig) {
    if(this != &orig){
        this->operator=(orig);
    }
    return *this;
}
