//
// Created by Galaxyraul on 09/05/2022.
//

#include "ContenedorItem.h"
#include <stdexcept>
#include "EmptyContainer.h"

int ContenedorItem::cuantosCaben() {
    return 0;
}

int ContenedorItem::cuantosHay() const {
    return _numItems;
}

void ContenedorItem::mete(Item *item) {
    if (!item)
        throw std::invalid_argument ("[Cofre::mete] Intento de asignar puntero 0");
    if (_numItems==_maxItems)
        throw std::out_of_range("[Cofre::mete] No caben más elementos en el cofre");
    _items[_numItems++]=item;
}

Item &ContenedorItem::consulta(int cual) {
    if (_numItems==0)
        throw EmptyContainer("[Cofre::consulta] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}

Item *ContenedorItem::saca(int cual) {
    if (_numItems==0)
        throw EmptyContainer("[Cofre::saca] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
}

ContenedorItem::ContenedorItem(int maxItems) : _maxItems(maxItems) {
    _items=new Item*[maxItems];
    for (int i = 0; i < maxItems; i++) {
        _items[i]=nullptr;
    }
}

ContenedorItem::ContenedorItem():
        ContenedorItem(27){}

ContenedorItem::~ContenedorItem() {
    delete [] _items;
}
