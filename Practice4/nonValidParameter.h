//
// Created by cocol on 12/03/2022.
//

#ifndef PRACTICE2_NONVALIDPARAMETER_H
#define PRACTICE2_NONVALIDPARAMETER_H
#include "string"
/**
 * @param _File File which throws the exception
 * @param _Function Function which throws the exception
 * @param _Description Description of the error encountered
 */
class nonValidParameter {
private:
    std::string _File ="";
    std::string _Function = "";
    std::string _Description = "";
public:
    nonValidParameter(const std::string &file, const std::string &function, const std::string &description);

    const std::string whatsHappening (const nonValidParameter& otro);

    const std::string &getFile() const;

    void setFile(const std::string &file);

    const std::string &getFunction() const;

    void setFunction(const std::string &function);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

};



#endif //PRACTICE2_NONVALIDPARAMETER_H
