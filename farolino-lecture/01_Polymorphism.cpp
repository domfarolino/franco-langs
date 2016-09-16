#include <iostream>

using namespace std;

/**
 * Base class "Employee"
 */
class Employee {
public:
  double baseWage;

  Employee(double inputBaseWage = 0) {
    this->baseWage = inputBaseWage;
  }

  double getCalculatedWage() {
    return baseWage;
  }

};

/**
 * Descendant of Employee
 * Salesmen wages = baseWage + 10%
 */
class Salesman : public Employee {
public:
  Salesman(double inputBaseWage): Employee(inputBaseWage) {
    /* don't really need to do anything */
  }

  double getCalculatedWage() {
    return baseWage+(baseWage*.1);
  }

};

/**
 * Descendant of Employee
 * Programmer wages = baseWage + 40%
 */
class Programmer : public Employee {
public:
  Programmer(double inputBaseWage): Employee(inputBaseWage) {
    /* don't really need to do anything */
  }

  double getCalculatedWage() {
    return baseWage+(baseWage*.4);
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

  cout << "baseEmployee->getCalculatedWage: " << baseEmployee->getCalculatedWage() << endl;
  cin.get();
  cout << "salesman->getCalculatedWage: "     << salesman->getCalculatedWage()     << endl;
  cin.get();
  cout << "programmer->getCalculatedWage: "   << programmer->getCalculatedWage()   << endl;
  cin.get();

  getEmployeeWage(baseEmployee);
  cin.get();
  getEmployeeWage(salesman);
  cin.get();
  getEmployeeWage(programmer);

  return 0;
}