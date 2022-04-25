/**
 * @file Device.cpp
 * @author ujapoo
 */

#include "Device.h"

Device::Device(const std::string& descripcion, float consumption)
		:_description(descripcion), _consumption(consumption)
{

}
const std::string& Device::getDescription() const
{
	return _description;
}

float Device::getConsumption() const
{
	return _consumption;
}

bool Device::isActive() const
{
	return active;
}

/** Cambia el estado de actividad del dispositivo
 */
void Device::switchState()
{
	if (this->active==false) {
		this->active = true;
	} else {
		this->active = false;
	}
}

