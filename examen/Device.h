/**
 * @file Device.h
 * @author ujapoo
 */
#ifndef CLOUDPOO_DEVICE_H
#define CLOUDPOO_DEVICE_H

#include <string>

class Device {
private:
	std::string _description;
	float _consumption;
	bool active = false;
public:
	Device(const std::string& descripcion, float consumption);
	Device(const Device& orig) = default;
	virtual ~Device() = default;

	const std::string& getDescription() const;
	float getConsumption() const;
	bool isActive() const;

	void switchState();

};

#endif //CLOUDPOO_DEVICE_H
