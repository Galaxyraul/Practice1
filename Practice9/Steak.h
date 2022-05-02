//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_STEAK_H
#define PRUEBA_STEAK_H
#include "Item.h"

class Steak: public Item {
    std::string getDescription() override;

public:
    Steak();
};


#endif //PRUEBA_STEAK_H
