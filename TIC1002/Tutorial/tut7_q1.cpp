#include <iostream>
using namespace std;

class Person {
private:
  string name;
  int age;
  Person *mother;

public:
  Person(){}

  Person(string name, int age)
  {
    this->name = name;
    this->age = age;
  }

  Person(string name, int age, Person *person)
  {
    this->name = name;
    this->age = age;
    this->mother = person;
  }

  string get_name() { return name; }
  int get_age() { return age; }
  Person *get_mother() { return mother; }
};

int my_main() { // Note this is correct because we cannot have a main function on Coursemology.
  Person a;
  Person sally("Sally", 32);
  Person thomas("Thomas", 6, &sally);
  cout << sally.get_name() << " is the mother of " << thomas.get_name() << endl;
  cout << "their age difference is " << sally.get_age() - thomas.get_age() << " years" << endl;

  return 0; 
}

int main () {
  cout << my_main(); 

  return 0; 
}