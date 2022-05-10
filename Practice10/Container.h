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

    Container(T1 maxItems) ;

    virtual ~Container();

    T1 cuantosCaben();

    T1 cuantosHay() const;

    virtual void mete(T2 *item);

    T2& consulta(T1 cual);

    T2* saca(T1 cual);

};
template <typename T1,typename T2>
Container<T1,T2>::Container(T1 maxItems): _maxItems(maxItems) {
    _items=new T2*[maxItems];
    for(int i = 0; i < maxItems;++i){
        _items[i] = nullptr;
    }
}

template<typename T1,typename T2>
Container<T1,T2>::~Container(){
    delete [] _items;
    _items = nullptr;
}
template<typename T1,typename T2>
T1 Container<T1, T2>::cuantosCaben(){
    return _maxItems - _numItems;
}

template<typename T1,typename T2>
T1 Container<T1, T2>::cuantosHay() const {
    return _numItems;
}

template<typename T1,typename T2>
void Container<T1,T2>::mete(T2 *item){
    if (item == nullptr){
        throw std::invalid_argument ("[Container<T>::mete] Intento de asignar puntero 0");
    }
    if (_numItems==_maxItems) {
        throw std::out_of_range("[Container<T>::mete] No caben más elementos en el cofre");
    }
    _items[_numItems++]=item;
}

template<typename T1,typename T2>
T2& Container<T1,T2>::consulta(T1 cual) {
    if (_numItems==0)
        throw EmptyContainer("[Container<T>::consulta] El container está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Container<T>::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}

template<typename T1,typename T2>
T2* Container<T1,T2>::saca(T1 cual){
    if (_numItems==0)
        throw EmptyContainer("[Container<T>::saca] El container está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Container<T>::mete] El elemento indicado no existe");
    T2* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
}



#endif //PRUEBA_CONTAINER_H
