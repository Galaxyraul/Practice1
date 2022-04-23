//
// Created by cocol on 16/04/2022.
//

#ifndef PRUEBA_MENTALPOWER_H
#define PRUEBA_MENTALPOWER_H
#include "Power.h"


class MentalPower: public Power{
private:
    float _lucidity = 0;
public:
    float getLucidity() const;

    void setLucidity(float lucidity);

public:
    MentalPower();

    MentalPower(const std::string &name, const std::string &description, const std::string &effectiveOn,
                float destructiveCapacity);

    MentalPower(const Power &orig);

    MentalPower &operator= (const MentalPower& orig);

    virtual float getDestructiveCapacity() const override;

};


#endif //PRUEBA_MENTALPOWER_H
