#include <iostream>

using namespace std;

/**
 * First level
 */
class Vehicle {
  //virtual void goForward() = 0;
  //virtual void startVehicle() = 0;
};

/**
 * Second level
 */

class GasVehicle: public Vehicle {

};

class SolarVehicle: public Vehicle {

};

class LandVehicle: public Vehicle {

};

class WaterVehicle: public Vehicle {

};

/**
 * Third level
 */

class GasPoweredLandVehicle: public GasVehicle, LandVehicle {

};

class GasPoweredWaterVehicle: public GasVehicle, WaterVehicle {

};

class SolarPoweredLandVehicle: public SolarVehicle, LandVehicle {

};

class SolarPoweredWaterVehicle: public SolarVehicle, WaterVehicle {

};

int main() {

  return 0;
}