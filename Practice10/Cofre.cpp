/**
 * @file    Cofre.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Cofre.h"
#include "EmptyContainer.h"
#include <stdexcept>
#include <sstream>

Cofre::Cofre(): ContenedorItem(27){}

void Cofre::mete(Item *item) {
    ContenedorItem::mete(item);
}

std::string Cofre::getDescripcion() const {
    std::stringstream ss;
    ss<<"Cofre que contiene (" << cuantosHay() <<") items";
    return ss.str();

}

