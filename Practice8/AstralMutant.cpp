//
// Created by Galaxyraul on 26/04/2022.
//

#include "AstralMutant.h"
#include <string>
#include <iostream>

void AstralMutant::attack(){
    if(_attacked){
        throw std::out_of_range("AstalMutant.cpp::attack:This mutant has already attacked");
    }
    _attacked=!_attacked;
}

void AstralMutant::addPower(const MentalPower &orig) {
    if(_numPowers == 1){
        throw std::out_of_range("AstralMutant.cpp::addMentalPower:An astral mutant cannot have more than a Mental power");
    }
    Mutante::addPower(orig);
    ++_numPowers;
}


void AstralMutant::addPower(const string &name, const std::string description, const std::string effectiveOn,
                            float capacityOfD, bool inhibited) {
    throw std::invalid_argument("AstralMutant.cpp::addPower:You can only add mental powers");
}

void AstralMutant::addMentalPower(const string &name, const std::string description, const std::string effectiveOn,
                                  float capacityOfD, bool inhibited, float lucidity) {
    if(_numPowers == 1){
        throw std::out_of_range("AstralMutant.cpp::addMentalPower:An astral mutant cannot have more than a Mental power");
    }
    Mutante::addMentalPower(name, description, effectiveOn, capacityOfD, inhibited, lucidity);
    _numPowers++;
}

void AstralMutant::addPhysicalPower(const string &name, const std::string description, const std::string effectiveOn,
                                    float capacityOfD, bool inhibited) {
    throw std::invalid_argument("AstralMutant.cpp::addPhysicalPower:You can only add mental powers");
}

void AstralMutant::addPower(const Power &orig) {
    throw std::invalid_argument("AstralMutant.cpp::addPower:You can only add mental powers");
}

void AstralMutant::addPower(const PhysicalPower &orig) {
    throw std::invalid_argument("AstralMutant.cpp::addPhysicalPower:You can only add mental powers");
}

AstralMutant::AstralMutant(const string &nombre, const string &apodo, int fechaN, const string &nacionalidad,
                           bool attacked, int numPowers) : Mutante(nombre, apodo, fechaN, nacionalidad),
                                                           _attacked(attacked), _numPowers(numPowers) {}

AstralMutant::AstralMutant(const Mutante &orig, bool attacked, int numPowers) : Mutante(orig), _attacked(attacked),
                                                                                _numPowers(numPowers) {}

AstralMutant::AstralMutant() {}

float AstralMutant::totalDestructiveCapacity() {
    if(_attacked){
        throw std::out_of_range("AstralMutant.cpp::totalDestructiveCapacity:The mutant has already attacked");
    }
    _attacked=!_attacked;
    return Mutante::totalDestructiveCapacity();
}
