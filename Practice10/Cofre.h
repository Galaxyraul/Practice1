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

#ifndef COFRE_H
#define COFRE_H

class Cofre: public ContenedorItem,public Item{
public:
    Cofre();

    void mete(Item *item) override;

    virtual std::string getDescripcion() const;





};

#endif /* COFRE_H */

