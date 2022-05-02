//
// Created by cocol on 02/05/2022.
//

#ifndef PRUEBA_EMPTYCONTAINER_H
#define PRUEBA_EMPTYCONTAINER_H
#include <stdexcept>


class EmptyContainer:public std::domain_error {
public:
    EmptyContainer(std::string error):std::domain_error(error){};
    virtual ~EmptyContainer() noexcept =default;
};


#endif //PRUEBA_EMPTYCONTAINER_H
