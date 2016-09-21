#include <iostream>

using namespace std;

/**
 * Engine Hierarchy
 */

/**
 * First level
 */
class Engine {
public:
  virtual string getType() = 0;
};

/**
 * Second level
 */

class GasEngine: public Engine {
public:
  string getType() {
    return "Gas";
  }
};

class SolarEngine: public Engine {
  string getType() {
    return "Solar";
  }
};

/**
 * Vehicle hierarchy
 */

/**
 * First level
 */
class Vehicle {
protected:
  Engine* engine;

public:
  Vehicle(Engine* inputEngine) {
    this->engine = inputEngine;
  }

  virtual void goForward() = 0;

  ~Vehicle() {
    delete this->engine;
  }
};

/**
 * Second level
 */

class LandVehicle: public Vehicle {
public:
  LandVehicle(Engine* inputEngine): Vehicle(inputEngine) {

  }

  void goForward() {
    cout << "I'm moving forward on land because I'm a land vehicle with a " << this->engine->getType() << " powered engine" << endl;
  }

};

class WaterVehicle: public Vehicle {
public:
  WaterVehicle(Engine* inputEngine): Vehicle(inputEngine) {

  }

  void goForward() {
    cout << "I'm moving forward in water because I'm a water vehicle with a " << this->engine->getType() << " powered engine" << endl;
  }

};

int main() {
  LandVehicle* gasLandVehicle = new LandVehicle(new GasEngine());
  gasLandVehicle->goForward();

  WaterVehicle* solarWaterVehicle = new WaterVehicle(new SolarEngine());
  solarWaterVehicle->goForward();

  delete gasLandVehicle;
  delete solarWaterVehicle;
  return 0;
}