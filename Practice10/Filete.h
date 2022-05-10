/** 
 * @file    Filete.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#ifndef FILETE_H
#define FILETE_H

#include "Item.h"

class Filete: public Item {
public:
    Filete() = default;
    Filete(const Filete& orig);
    virtual ~Filete();

    virtual std::string getDescripcion() const;

    bool operator==(Item& i1) const override;

private:

};

#endif /* FILETE_H */

