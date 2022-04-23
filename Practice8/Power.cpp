//
// Created by cocol on 16/04/2022.
//

#include "Power.h"
#include <sstream>

Power::Power(const Power &orig):
    _name(orig._name),
    _description(orig._description),
    _destructiveCapacity(orig._destructiveCapacity),
    _effectiveOn(orig._effectiveOn) {

}

Power::Power() {}

const std::string &Power::getName() const {
    return _name;
}

void Power::setName(const std::string &name) {
    _name = name;
}

const std::string &Power::getDescription() const {
    return _description;
}

void Power::setDescription(const std::string &description) {
    _description = description;
}

const std::string &Power::getEffectiveOn() const {
    return _effectiveOn;
}

void Power::setEffectiveOn(const std::string &effectiveOn) {
    _effectiveOn = effectiveOn;
}

float Power::getDestructiveCapacity() const {
    return _destructiveCapacity;
}

void Power::setDestructiveCapacity(float destructiveCapacity) {
    _destructiveCapacity = destructiveCapacity;
}

Power::Power(const std::string &name, const std::string &description, const std::string &effectiveOn,
             float destructiveCapacity) : _name(name), _description(description), _effectiveOn(effectiveOn),
                                          _destructiveCapacity(destructiveCapacity) {}

Power Power::operator=(const Power &orig) {
    if(this != &orig){
        _effectiveOn = orig._effectiveOn;
        _name = orig._name;
        _description = orig._description;
        _destructiveCapacity = orig._destructiveCapacity;
    }
    return *this;
}

std::string Power::toCSV() const {
    std::stringstream s;
    s<<_name <<";"<<_description<<";"<<_effectiveOn<<";"<<_destructiveCapacity;
    return s.str();
}

Power::~Power() {

}
