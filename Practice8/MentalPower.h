//
// Created by cocol on 16/04/2022.
//

#ifndef PRUEBA_MENTALPOWER_H
#define PRUEBA_MENTALPOWER_H
#include "Power.h"

class MentalPower: public Power{
public:
    MentalPower();

    MentalPower(const std::string &name, const std::string &description, const std::string &effectiveOn,
                float destructiveCapacity);

    MentalPower(const Power &orig);

    MentalPower &operator= (const MentalPower& orig);

};


#endif //PRUEBA_MENTALPOWER_H
