/**
 * @file Generator.h
 * @author ujapoo
 */

#ifndef CLOUDPOO_GENERATOR_H
#define CLOUDPOO_GENERATOR_H

#include <string>

class Generator {
private:
	std::string _modeL;
	float _power;
public:
	Generator(const std::string& model, float power);
	Generator(const Generator& orig) = default;
	virtual ~Generator() = default;

	const std::string& getModel() const;

	float getPower() const;
};

#endif //CLOUDPOO_GENERATOR_H
