//
// Created by cocol on 27/03/2022.
//

#ifndef PRUEBA_PART_H
#define PRUEBA_PART_H
#include <string>

class Part {
private:
    std::string _name = "";
    float _weight = 0;
    std::string _description = "";
public:
    Part();

    Part(const std::string &name);

    Part(const std::string &name, float weight);

    Part(const std::string &name, float weight, const std::string &description);

    Part(const Part& orig);

    virtual ~Part();
};


#endif //PRUEBA_PART_H
