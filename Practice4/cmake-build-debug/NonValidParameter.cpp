//
// Created by cocol on 12/03/2022.
//

#include "NonValidParameter.h"

nonValidParameter::nonValidParameter(const std::string &file, const std::string &function,
                                     const std::string &description) : _File(file), _Function(function),
                                                                       _Description(description) {}

const std::string nonValidParameter::whatsHappening(const nonValidParameter &otro) {
    return "The file:" + _File + " in the function:" + _Function + " has the following problem:" + _Description;
}

const std::string &nonValidParameter::getFile() const {
    return _File;
}

void nonValidParameter::setFile(const std::string &file) {
    _File = file;
}

const std::string &nonValidParameter::getFunction() const {
    return _Function;
}

void nonValidParameter::setFunction(const std::string &function) {
    _Function = function;
}

const std::string &nonValidParameter::getDescription() const {
    return _Description;
}

void nonValidParameter::setDescription(const std::string &description) {
    _Description = description;
}
