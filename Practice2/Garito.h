//
// Created by cocol on 26/02/2022.
//

#ifndef PRACTICE2_GARITO_H
#define PRACTICE2_GARITO_H
#include <string>

class Garito {
private:
    std::string _name = "";
    std::string _address = "";
public:
    Garito(const std::string &name, const std::string &address);

    Garito(const Garito& orig);

    virtual ~Garito();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getAddress() const;

    void setAddress(const std::string &address);

};


#endif //PRACTICE2_GARITO_H
