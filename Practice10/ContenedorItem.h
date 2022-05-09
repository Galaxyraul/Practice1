//
// Created by Galaxyraul on 09/05/2022.
//

#ifndef PRUEBA_CONTENEDORITEM_H
#define PRUEBA_CONTENEDORITEM_H
#include "Item.h"
class ContenedorItem {
private:
    int _maxItems = 0;

    Item** _items = nullptr;

    int _numItems = 0;
public:
    ContenedorItem();

    ContenedorItem(int maxItems);

    virtual ~ContenedorItem();

    int cuantosCaben();

    int cuantosHay() const;

    virtual void mete(Item *item);

    Item& consulta(int cual);

    Item* saca(int cual);

};



#endif //PRUEBA_CONTENEDORITEM_H
