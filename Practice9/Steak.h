//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_STEAK_H
#define PRUEBA_STEAK_H
#include "Item.h"

class Steak: public Item {
public:
    Steak(const std::string &description);

private:
    std::string _description = "";
public:
    Steak();

    std::string getDescription() override;

};


#endif //PRUEBA_STEAK_H
