//
// Created by cocol on 02/05/2022.
//

#include "Sword.h"

std::string Sword::getDescription() {
    return "A sword";
}

Sword::Sword() {}

Sword::Sword(const std::string &description) : _description(description) {}
