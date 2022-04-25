/**
 * @file Generator.cpp
 * @author ujapoo
 */
#include "Generator.h"

Generator::Generator(const std::string& cadena, float power)
		:_modeL(cadena), _power(power)
{

}

const std::string& Generator::getModel() const
{
	return _modeL;
}

float Generator::getPower() const
{
	return _power;
}
