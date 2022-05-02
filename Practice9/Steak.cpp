//
// Created by cocol on 02/05/2022.
//

#include "Steak.h"

std::string Steak::getDescription() {
    return "A steak";
}

Steak::Steak() {}

Steak::Steak(const std::string &description) : _description(description) {}
