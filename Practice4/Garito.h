//
// Created by cocol on 26/02/2022.
//

#ifndef PRACTICE2_GARITO_H
#define PRACTICE2_GARITO_H
#include <string>
#include "Fecha.h"

/**
 * @brief This class will store the objects of the type garito
 * @param _name Name of the garito
 * @param _address Address of the garito
 * @param _dateOfLastShow Date in which this garito was lastly used
 */
class Garito {
private:
    std::string _name = "";
    std::string _address = "";
    Fecha _dateOfLastShow;
public:
    Garito();

    Garito(const std::string &name, const std::string &address);

    Garito(const Garito& orig);

    virtual ~Garito();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getAddress() const;

    void setAddress(const std::string &address);

    void setDateOfLastShow(int day,int month,int year);

    const Fecha &getDateOfLastShow() const;

    const std::string toCSV() const;

};


#endif //PRACTICE2_GARITO_H
