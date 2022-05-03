//
// Created by Galaxyraul on 03/05/2022.
//

#ifndef PRUEBA_SNOWBALL_H
#define PRUEBA_SNOWBALL_H
#include "ItemApilableArrojable.h"

class SnowBall: public ItemApilableArrojable{
private:
    std::string _description = "Snowball";
public:
    SnowBall(int numberOfElements);

    float lanzar() override;

    std::string getDescription() override;



};


#endif //PRUEBA_SNOWBALL_H
