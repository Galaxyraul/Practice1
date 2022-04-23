//
// Created by cocol on 16/04/2022.
//

#ifndef PRUEBA_POWER_H
#define PRUEBA_POWER_H
#include "String"

class Power {
protected:
    std::string _name = "";
    std::string _description = "";
    std::string _effectiveOn = "";
    float _destructiveCapacity = 0;
public:
    Power();

    Power(const std::string &name, const std::string &description, const std::string &effectiveOn,
          float destructiveCapacity);

    Power(const Power& orig);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getEffectiveOn() const;

    void setEffectiveOn(const std::string &effectiveOn);

    virtual float getDestructiveCapacity() const;

    virtual void setDestructiveCapacity(float destructiveCapacity);

    Power operator = (const Power& orig);

    virtual std::string toCSV () const;

    virtual ~Power();


};


#endif //PRUEBA_POWER_H
