/** 
 * @file    Cofre.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Item.h"
#include <string>
#include "ContenedorItem.h"
#include "Item.h"
#include "Container.h"

#ifndef COFRE_H
#define COFRE_H
template<class T1,class T2>
class Cofre: public ContenedorItem,public Item,public Container<T1,T2>{
public:
    Cofre();

    void mete(Item *item) override;

    std::string getDescripcion() const override;





};

#endif /* COFRE_H */

