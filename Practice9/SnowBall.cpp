//
// Created by Galaxyraul on 03/05/2022.
//

#include "SnowBall.h"
#include <iostream>
#include <sstream>

float SnowBall::lanzar() {
    try{
        decreaseStack(1);
    }catch (std::out_of_range& e){
        std::cerr<<e.what();
    }
    return getDamage();
}

std::string SnowBall::getDescription() {
    std::stringstream ss;
    ss<< getNumberOfPiledElements();
    std::string a = "SnowBall (" + ss.str() +')';
    return a;
}

SnowBall::SnowBall(int numberOfElements) : ItemApilableArrojable(numberOfElements,1){}
