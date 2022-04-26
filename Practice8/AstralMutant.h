//
// Created by Galaxyraul on 26/04/2022.
//

#ifndef PRUEBA_ASTRALMUTANT_H
#define PRUEBA_ASTRALMUTANT_H
#include "Mutante.h"


class AstralMutant:public Mutante {
private:
    bool _attacked = false;
    int _numPowers = 0;
public:
    AstralMutant();

    AstralMutant(const Mutante &orig, bool attacked, int numPowers);

    AstralMutant(const string &nombre, const string &apodo, int fechaN, const string &nacionalidad, bool attacked,
                 int numPowers);

    void attack();

    virtual void addPower(const MentalPower& orig) override;

    virtual void addPower (const std::string &name, const std::string description, const std::string effectiveOn,float capacityOfD,bool inhibited ) override;

    virtual void addMentalPower(const std::string &name, const std::string description, const std::string effectiveOn,float capacityOfD,bool inhibited,float lucidity ) override;

    virtual void addPhysicalPower(const std::string &name, const std::string description, const std::string effectiveOn,float capacityOfD,bool inhibited) override;

    virtual void addPower (const Power& orig) override;

    virtual void addPower (const PhysicalPower& orig) override;

    virtual float totalDestructiveCapacity () override;

};


#endif //PRUEBA_ASTRALMUTANT_H
