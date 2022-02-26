//
// Created by cocol on 26/02/2022.
//

#include "Garito.h"

Garito::Garito(const std::string &name, const std::string &address) : _name(name), _address(address) {}

Garito::Garito(const Garito& orig) : _name(orig._name), _address(orig._address) {}

Garito::~Garito() {

}

const std::string &Garito::getName() const {
    return _name;
}

void Garito::setName(const std::string &name) {
    if (name == ""){
        throw std::string ("The name cannot be the empty chain");
    }
    this->_name = name;
}

const std::string &Garito::getAddress() const {
    return _address;
}

void Garito::setAddress(const std::string &address) {
    if (address == ""){
        throw std::string ("The address  cannot be the empty chain");
    }
    this->_address = address;
}


