#include <iostream>
#include <string>

using namespace std;

/**
 * First level
 */
class TopClass {
public:
  string topMember;
};

/**
 * Second level
 */

class LeftClass: public TopClass {
public:
  string leftMember;
};

class RightClass: public TopClass {
public:
  string rightMember;
};

/**
 * Third level
 */

class BottomClass: public LeftClass, public RightClass {
public:
  string bottomMember;
};

int main() {
  BottomClass* bottomClass = new BottomClass();

  bottomClass->topMember = "topMember";

  // Addresses
  return 0;
}