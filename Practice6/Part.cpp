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



