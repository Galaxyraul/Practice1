//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_BLOCK_H
#define PRUEBA_BLOCK_H
#include "Item.h"

class Block: public Item {
    std::string getDescription() override;

public:
    Block();
};


#endif //PRUEBA_BLOCK_H
