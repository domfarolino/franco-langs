#include <iostream>

using namespace std;

/**
 * Base class "Employee"
 */
class Employee {
protected:
  double baseWage;

public:
  Employee(double inputBaseWage) {
    this->baseWage = inputBaseWage;
  }

  double getCalculatedWage() {
    return baseWage;
  }

};

/**
 * Descendant of Employee
 * Salesmen wage = baseWage + 10%
 */
class Salesman: public Employee {
public:
  Salesman(double inputBaseWage): Employee(inputBaseWage) {
    /* don't really need to do anything */
  }

  double getCalculatedWage() {
    return this->baseWage + (this->baseWage*.1);
  }

};

/**
 * Descendant of Employee
 * Programmer wage = baseWage + 40%
 */
class Programmer: public Employee {
public:

  Programmer(double inputBaseWage): Employee(inputBaseWage) {
    /* don't really need to do anything */
  }

  double getCalculatedWage() {
    return this->baseWage + (this->baseWage*.4);
  }

};

/**
 * Super versatile library function that
 * accepts ANY employee...but does it work?
 */
void getEmployeeWage(Employee* inputEmployee) {
  cout << "The calculated wage for the input employee is: " << inputEmployee->getCalculatedWage() << endl;
}

int main() {
  Employee* baseEmployee = new Employee(100.00);
  Salesman* salesman     = new Salesman(100.00);
  Programmer* programmer = new Programmer(100.00);

  cout << "baseEmployee->getCalculatedWage:   " << baseEmployee->getCalculatedWage() << endl;
  cin.get();
  cout << "salesman->getCalculatedWage:       " << salesman->getCalculatedWage()     << endl;
  cin.get();
  cout << "programmer->getCalculatedWage:     " << programmer->getCalculatedWage()   << endl;
  cin.get();

  getEmployeeWage(baseEmployee);
  cin.get();
  getEmployeeWage(salesman);
  cin.get();
  getEmployeeWage(programmer);
  cin.get();

  cout << ((Employee*)salesman)->getCalculatedWage() << endl;
  cout << ((Employee*)programmer)->getCalculatedWage() << endl;

  delete baseEmployee;
  delete salesman;
  delete programmer;
  return 0;
}