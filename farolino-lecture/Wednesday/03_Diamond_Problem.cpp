#include <iostream>
#include <string>

using namespace std;

class TopClass {
public:
  string topMember;
};

class LeftClass: public TopClass {
public:
  string leftMember;
};

class RightClass: public TopClass {
public:
  string rightMember;
};

class BottomClass: public LeftClass, public RightClass {
public:
  string bottomMember;
};

int main() {
  BottomClass* bottomClass = new BottomClass();

  bottomClass->topMember = "topMember";

  // Addresses/Disambiguate
  return 0;
}