//
// Created by Galaxyraul on 13/05/2022.
//

#ifndef POOFUSION_GIT_FIXINGERROR_H
#define POOFUSION_GIT_FIXINGERROR_H
#include <stdexcept>

class FixingError: public std::invalid_argument{
public:
    FixingError(const std::string &arg);

};


#endif //POOFUSION_GIT_FIXINGERROR_H
