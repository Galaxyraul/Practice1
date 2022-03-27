//
// Created by cocol on 27/03/2022.
//

#include "Part.h"

Part::Part() {}

Part::Part(const std::string &name) : _name(name) {}

Part::Part(const std::string &name, float weight) : _name(name), _weight(weight) {}

Part::Part(const std::string &name, float weight, const std::string &description) : _name(name), _weight(weight),
                                                                                    _description(description) {}

Part::~Part() {

}

Part::Part(const Part &orig) :_weight(orig._weight),_name(orig._name),_description(orig._description)
{}

const std::string &Part::getName() const {
    return _name;
}

void Part::setName(const std::string &name) {
    _name = name;
}

float Part::getWeight() const {
    return _weight;
}

void Part::setWeight(float weight) {
    _weight = weight;
}

const std::string &Part::getDescription() const {
    return _description;
}

void Part::setDescription(const std::string &description) {
    _description = description;
}



