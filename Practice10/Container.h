//
// Created by cocol on 09/05/2022.
//

#ifndef PRUEBA_CONTAINER_H
#define PRUEBA_CONTAINER_H

#include "Item.h"
#include <stdexcept>
#include "EmptyContainer.h"
template<typename T1,typename T2>
class Container {
private:
    T1 _maxItems = 0;

    T2** _items = nullptr;

    T1 _numItems = 0;
public:
    Container() = default;

    Container(int maxItems);

    Container(T1 maxItems) : _maxItems(maxItems) {}

    virtual ~ContenedorItem(){
        delete [] _items;
    }

    T1 cuantosCaben(){
        return _maxItems - _numItems;
    }

    T1 cuantosHay() const{
        return _numItems;
    }

    virtual void mete(T2 *item){
        if (!item)
            throw std::invalid_argument ("[Cofre::mete] Intento de asignar puntero 0");
        if (_numItems==_maxItems)
            throw std::out_of_range("[Cofre::mete] No caben más elementos en el cofre");
        _items[_numItems++]=item;
    }

    Item& consulta(T1 cual){
        if (_numItems==0)
            throw EmptyContainer("[Cofre::consulta] El cofre está vacío");
        if (cual<=0 || cual >_numItems)
            throw std::out_of_range("[Cofre::consulta] El elemento indicado no existe");
        return *_items[cual-1];
    }

    T2* saca(T1 cual){
        if (_numItems==0)
            throw EmptyContainer("[Cofre::saca] El cofre está vacío");
        if (cual<=0 || cual >_numItems)
            throw std::out_of_range("[Cofre::mete] El elemento indicado no existe");
        T2* elemento = _items[cual-1];
        _numItems--;
        if (_numItems>0)
            _items[cual-1]=_items[_numItems];
        return elemento;
    }

};

#endif //PRUEBA_CONTAINER_H
