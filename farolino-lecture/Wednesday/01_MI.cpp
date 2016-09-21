#include <iostream>
#include <string>

using namespace std;

class Person {
private:
  string name;
  int age;

public:
  Person(string inputName, int inputAge): name(inputName), age(inputAge) {
    // no work to do here
  }

  string getName() {
    return this->name;
  }

  int getAge() {
    return this->age;
  }
};

class Employee {
private:
  string jobTitle;
  double baseWage;

public:
  Employee(string inputJobTitle, double inputBaseWage): jobTitle(inputJobTitle), baseWage(inputBaseWage) {
    // again no work to do here
  }

  double getBaseWage() {
    return this->baseWage;
  }

  string getJobTitle() {
    return this->jobTitle;
  }
};

class Teacher: public Person, public Employee {
private:
  string roomNumber;

public:                                  // Lots of teacher parameters (teacher + employee + person)               Person can deal wtih these...     Employee can deal with these...     and we can deal with this!
  Teacher(string inputName, int inputAge, string inputJobTitle, double inputBaseWage, string inputRoomNumber): Person(inputName, inputAge), Employee(inputJobTitle, inputBaseWage), roomNumber(inputRoomNumber) {
    // AGAIN no work to do here
  }

  string getRoomNumber() {
    return roomNumber;
  }
};

void getTeacherInformation(Teacher* teacher) {
  cout << "Current teacher is named " << teacher->getName()
        << " and is " << teacher->getAge()
        << " years of age and is a " << teacher->getJobTitle()
        << " for $" << teacher->getBaseWage() << " in " << teacher->getRoomNumber() << endl;
}

int main() {
  Teacher* teacher = new Teacher("Dom", 21, "prog langs temp prof", 0.0, "Swfit 520");
  
  getTeacherInformation(teacher);
  
  delete teacher;
  return 0;
}