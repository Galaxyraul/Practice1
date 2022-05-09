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
template <typename T1,typename T2>
Cofre<T1,T2>::Cofre(): ContenedorItem(27){}

template<typename T1,typename T2>
void Cofre<T1,T2>::mete(Item *item) {
    if(dynamic_cast<Cofre*>(item)){
        throw std::invalid_argument("Cofre.cpp::Mete:You cannot put a chest into a chest");
    }
    ContenedorItem::mete(item);
}
template<typename T1,typename T2>
std::string Cofre<T1,T2>::getDescripcion() const {
    std::stringstream ss;
    ss<<"Cofre que contiene (" << cuantosHay() <<") items";
    return ss.str();
}

