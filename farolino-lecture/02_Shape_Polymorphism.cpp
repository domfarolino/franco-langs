#include <iostream>
#include <typeinfo>

using namespace std;

/**
 * General base class `Shape`
 * knows that each specific shape
 * will have a width and height, however
 * the implementation for calculating area
 * will always differ. This is because there
 * is no such thing as a generic `shape`, every
 * existing shape is a more specific version of this
 * class.
 */
class Shape {
protected:
  int width, height;

public:
  Shape(int inputWidth, int inputHeight) {
    this->width = inputWidth;
    this->height = inputHeight;
  }
  
  virtual int getArea() = 0;

  void setWidth(int inputWidth) {
    this->width = inputWidth;
  }

  void setHeight(int inputHeight) {
    this->height = inputHeight;
  }

};

/**
 * Rectangle has some info
 * in common with `Shape` but
 * 
 */
class Rectangle: public Shape {
public:
  Rectangle(int inputWidth, int inputHeight): Shape(inputWidth, inputHeight) {
    // Don't really need to do anything here
  }

  int getArea() {
    return (this->width * this->height);
  }
};

class Triangle: public Shape {
public:
  Triangle(int inputWidth, int inputHeight): Shape(inputWidth, inputHeight) {
    // Don't really need to do anything here
  }

  int getArea() {
    return (this->width * this->height)/2;
  }
};

/**
 * Possible "library" function that needs
 * to work with any subclass of `Shape` given
 * to it.
 */
void printTypeAndArea(Shape* shape) {
  //cout << "Getting area for: " << typeid(shape).name() << endl;
  cout << shape->getArea() << endl;
}

int main() {
  // Shape* shape = new Shape(10, 20); // won't work

  Rectangle* rectangle = new Rectangle(5, 10);
  Triangle* triangle = new Triangle(5, 10);
  
  // Works as normal
  cout << rectangle->getArea() << endl;
  cin.get();
  cout << triangle->getArea() << endl;
  cin.get();
  
  printTypeAndArea(rectangle);
  cin.get();
  printTypeAndArea(triangle);
  cin.get();

  // Casting examples
  cout << ((Shape*)rectangle)->getArea() << endl;
  cin.get();
  cout << ((Shape*)triangle)->getArea() << endl;
  return 0;
}