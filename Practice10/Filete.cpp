/** 
 * @file    Filete.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Filete.h"

Filete::Filete(const Filete& orig) {
}

Filete::~Filete() {
}

std::string Filete::getDescripcion() const {
    return "Filete";
}

bool Filete::operator==(Item &i1) const {
    return true;
}
