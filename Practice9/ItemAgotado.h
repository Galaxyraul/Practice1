//
// Created by Galaxyraul on 03/05/2022.
//

#ifndef PRUEBA_ITEMAGOTADO_H
#define PRUEBA_ITEMAGOTADO_H
#include <stdexcept>
class ItemAgotado:public std::out_of_range{
public:
    ItemAgotado(const std::string &arg) : out_of_range(arg) {};
};
#endif //PRUEBA_ITEMAGOTADO_H
