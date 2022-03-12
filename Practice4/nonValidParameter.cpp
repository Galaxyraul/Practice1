//
// Created by cocol on 12/03/2022.
//

#include "nonValidParameter.h"
/**
 * @brief Parameterized constructor
 * @param file string that will be the value of the _file field
 * @param function string that will be the value of the _function field
 * @param description string that will be the value of the _description field
 */
nonValidParameter::nonValidParameter(const std::string &file, const std::string &function,
                                     const std::string &description) : _File(file), _Function(function),
                                                                       _Description(description) {}
/**
 * @brief Joins all the fields of the object so that is returned as string
 * @param otro Object from which the fields will be copied
 * @return string with the data
 */
const std::string nonValidParameter::whatsHappening(const nonValidParameter &otro) {
    return "The file:" + _File + " in the function:" + _Function + " has the following problem:" + _Description;
}
/**
 * @brief getter for the _File field
 * @return Value of the _File field
 */
const std::string &nonValidParameter::getFile() const {
    return _File;
}
/**
 * @brief setter for the _File field
 * @param file value to which the field _File will be assigned
 */
void nonValidParameter::setFile(const std::string &file) {
    _File = file;
}
/**
 * @brief getter for the _Function field
 * @return Value of the _Function field
 */
const std::string &nonValidParameter::getFunction() const {
    return _Function;
}
/**
 * @brief setter for the _Function field
 * @param file value to which the field _Function will be assigned
 */
void nonValidParameter::setFunction(const std::string &function) {
    _Function = function;
}
/**
 * @brief getter for the _Description field
 * @return Value of the _Description field
 */
const std::string &nonValidParameter::getDescription() const {
    return _Description;
}
/**
 * @brief setter for the _Description field
 * @param file value to which the field _Description will be assigned
 */
void nonValidParameter::setDescription(const std::string &description) {
    _Description = description;
}
