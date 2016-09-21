#include <iostream>
#include <vector>
#include <string>

using namespace std;

class List_Element {
public:
  virtual void doubleElement() = 0;
  virtual string getElement() const = 0;
};

class Integer_Element: public List_Element {
private:
  int element;

public:
  Integer_Element(int inputElement) {
    this->element = inputElement;
  }

  void doubleElement() {
    this->element = (this->element * 2);
  }

  string getElement() const {
    return to_string(element);
  }
};

class String_Element: public List_Element {
private:
  string element;

public:
  String_Element(string inputElement) {
    this->element = inputElement;
  }

  void doubleElement() {
    this->element = (this->element + this->element);
  }

  string getElement() const {
    return element;
  }

};

ostream& operator<<(ostream &output, const List_Element& listElement) {
  output << listElement.getElement();
  return output;
}

class List {
private:
  vector<List_Element*> v;

public:
  void add(List_Element* i) {
    v.push_back(i);
  }

  void doubleAllElements() {
    for (int i = 0; i < v.size(); ++i) {
      v[i]->doubleElement();
    }
  }

  void print() {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
      cout << *(v[i]) << ", ";
    }
    cout << "]" << endl;
  }

  ~List() {
    for (int i = 0; i < v.size(); ++i) {
      delete v[i];
    }
  }
};

int main() {
  List itemList;
  itemList.add(new Integer_Element(4));
  itemList.add(new String_Element("Dominic"));
  itemList.add(new String_Element("6"));
  itemList.add(new Integer_Element(100));
  itemList.print();
  itemList.doubleAllElements();
  itemList.print();
  return 0;
}