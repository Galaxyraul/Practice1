//
// Created by Galaxyraul on 09/05/2022.
//

#ifndef PRUEBA_INVENTARIO_H
#define PRUEBA_INVENTARIO_H
#include "ContenedorItem.h"
#include "Container.h"
template<typename T1,typename T2>
class Inventario: public ContenedorItem,public Container<T1,T2>{
public:
    Inventario();

};


#endif //PRUEBA_INVENTARIO_H
