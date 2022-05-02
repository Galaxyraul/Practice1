//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_SWORD_H
#define PRUEBA_SWORD_H
#include "Item.h"


class Sword: public Item{
private:
    std::string _description = "";
public:
    Sword(const std::string &description);

public:
    std::string getDescription() override;

    Sword();

};


#endif //PRUEBA_SWORD_H
