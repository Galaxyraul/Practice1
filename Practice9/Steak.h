//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_STEAK_H
#define PRUEBA_STEAK_H
#include "Item.h"

class Steak: public Item {
public:
    virtual ~Steak();

private:
    std::string _description = "";
public:
    Steak();

    std::string getDescription() override;

    Steak(const std::string &description);

};


#endif //PRUEBA_STEAK_H
