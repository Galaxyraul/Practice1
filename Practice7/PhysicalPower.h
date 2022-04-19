//
// Created by cocol on 16/04/2022.
//

#ifndef PRUEBA_PHYSICALPOWER_H
#define PRUEBA_PHYSICALPOWER_H
#include "Power.h"


class PhysicalPower: public Power{
public:
    PhysicalPower();

    PhysicalPower(const std::string &name, const std::string &description, const std::string &effectiveOn,
                  float destructiveCapacity,bool inhibited);

    PhysicalPower(const Power &orig);

    PhysicalPower &operator=(const PhysicalPower& orig);
};


#endif //PRUEBA_PHYSICALPOWER_H
