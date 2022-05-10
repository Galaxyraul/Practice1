//
// Created by Galaxyraul on 09/05/2022.
//

#ifndef PRUEBA_INVENTARIO_H
#define PRUEBA_INVENTARIO_H
#include "ContenedorItem.h"
#include "Container.h"

class Inventario:public Container<int,Item>{
public:
    Inventario();

};


#endif //PRUEBA_INVENTARIO_H
