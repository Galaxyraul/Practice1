//
// Created by Galaxyraul on 10/05/2022.
//

#ifndef PRUEBA_HMMMEXCEPTION_H
#define PRUEBA_HMMMEXCEPTION_H
#include <stdexcept>

class HmmmException: public std::domain_error{
public:
    HmmmException(const std::string &arg);

};


#endif //PRUEBA_HMMMEXCEPTION_H
