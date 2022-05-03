//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_BLOCK_H
#define PRUEBA_BLOCK_H
#include "ItemApilable.h"

class Block: public ItemApilable {
private:
    std::string _description = "";

public:
    Block();

    Block(int numberOfElements);

    std::string getDescription() override;

    Block(const std::string &description,int numberOfElements );

    Block(const std::string &description);

    virtual ~Block();
};


#endif //PRUEBA_BLOCK_H
