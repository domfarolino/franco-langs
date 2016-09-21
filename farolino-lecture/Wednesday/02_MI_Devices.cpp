#include <iostream>
#include <string>

using namespace std;

class NetworkDevice {
private:
  string deviceID;

public:
  NetworkDevice(string inputDeviceID): deviceID(inputDeviceID) {

  }

  string getDeviceID() {
    return "ND" + deviceID;
  }
};

class USBDevice {
private:
  string deviceID;

public:
  USBDevice(string inputDeviceID): deviceID(inputDeviceID) {

  }

  string getDeviceID() {
    return "USB" + deviceID;
  }
};

class WirelessAdapter: public NetworkDevice, public USBDevice {
public:
  WirelessAdapter(string networkID, string USBID): NetworkDevice(networkID), USBDevice(USBID) {

  }

  void someFunctionSpecificToWirelessAdapters() {
    //do some cool stuff here
  }

};

int main() {
  WirelessAdapter* wirelessAdapter = new WirelessAdapter("92494N", "292485U");

  cout << wirelessAdapter->getDeviceID() << endl;

  cout << "Network deviceID: " << wirelessAdapter->NetworkDevice::getDeviceID() << endl;
  cout << "USB deviceUD: " << wirelessAdapter->USBDevice::getDeviceID() << endl;
  return 0;
}