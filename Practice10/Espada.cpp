/** 
 * @file    Espada.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Espada.h"

Espada::Espada(const Espada& orig) {
}

Espada::~Espada() {
}

std::string Espada::getDescripcion() const {
    return "Espada";
}

bool Espada::operator==(Item &i1) const {
    return true;
}
