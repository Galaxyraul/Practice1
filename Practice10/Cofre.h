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

class Cofre:public Item,public Container<int,Item>{
public:
    Cofre();

    void mete(Item *item) override;

    std::string getDescripcion() const override;





};

#endif /* COFRE_H */

