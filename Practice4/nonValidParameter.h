//
// Created by cocol on 12/03/2022.
//

#ifndef PRACTICE2_NONVALIDPARAMETER_H
#define PRACTICE2_NONVALIDPARAMETER_H
#include "string"

class nonValidParameter {
private:
    std::string _File ="";
    std::string _Function = "";
public:
    const std::string &getFile() const;

    void setFile(const std::string &file);

    const std::string &getFunction() const;

    void setFunction(const std::string &function);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

private:
    std::string _Description = "";
public:
    nonValidParameter(const std::string &file, const std::string &function, const std::string &description);

    const std::string whatsHappening (const nonValidParameter& otro);
};



#endif //PRACTICE2_NONVALIDPARAMETER_H
