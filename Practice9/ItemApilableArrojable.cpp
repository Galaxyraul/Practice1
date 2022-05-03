//
// Created by Galaxyraul on 03/05/2022.
//

#include "ItemApilableArrojable.h"
#include <iostream>

float ItemApilableArrojable::lanzar() {
    try{
        decreaseStack(1);
    }catch (std::out_of_range& e){
        std::cerr<<e.what();
    }
    return _damage;
}
