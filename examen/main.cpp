/**
 * @file main.cpp
 * @author ujapoo
 */
#include <iostream>
#include "Generator.h"
#include "DataCenter.h"
#include "Device.h"
#include "string"

//TODO Has complicado innecesariamente la gestión de los dispositivos aunque la calidad del código es adecuada. Buen trabajo.

int main()
{
	/* Test 1: Create a Datacenter with 2 assigned technicians and three Devices with the following data:
	 * 500W Server Rack, 750W Disk RAID, 250W Backup Drive.*/

	/*Test 2: Create two 1500W Generators and try to assign them to the Datacenter.
	 *  Capture and display the exception information. Show the power of the DataCenter*/

	/*Test 3 : install the three devices to the dataCenter, catching any exceptions it may throw.*/

	/*Test 4. Create a DataCenter that is a copy of the existing one. With the copy, activate its first two devices,
	 display the current consumption of the DataCenter and the number of devices it has installed*/

    DataCenter dt1("jaén",200);
    dt1.setTechnicians(2);
    Device d1("Server Rack",500);
    Device d2("Disk Raid",750);
    Device d3("BackUp Drive",250);

    Generator g1("Electric co",1500);
    Generator g2("Electric co",1500);
    try{
        dt1.setSource(g1);
        dt1.setSource(g2);
    }catch (std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "The available power is:" << dt1.getPowerAvailable() << std::endl;

    try {
        dt1.installDevice(d1);
        dt1.installDevice(d2);
        dt1.installDevice(d3);
    }catch (std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
    DataCenter dt2 (dt1);
    dt2.getDevice(1)->switchState();
    dt2.getDevice(2)->switchState();
    std::cout << "The current consumptions is:" << dt2.currentComsuption() << std::endl;
    std::cout << "The number of devices installed is:" << dt2.getNumDevices() << std::endl;
	return 0;
}
