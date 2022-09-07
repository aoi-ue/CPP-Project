#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal
{
  /* TODO: Implement data and functionality of an Animal here */
private:
  string name;
  string sound;

public:
  Animal(string name, string sound)
  {
    this->name = name;
    this->sound = sound;
  }

  string getName() { return name; }
  string getSound() { return sound; }
};

class OldMcDonald
{
private:
  vector<Animal *> _farm; // Old McDonald had a farm (still has now)

public:
  OldMcDonald()
  {
    /* TODO: Create your farm, an Animal* vector */
    _farm.push_back(new Animal("Cow", "Moo"));
    _farm.push_back(new Animal("Dog", "Woof"));
    _farm.push_back(new Animal("Duck", "Quack"));
  }
  ~OldMcDonald()
  {
    /* TODO: Old McDonald has no (more) farm... */
    for (int i = 0; i < _farm.size(); i++)
      delete _farm[i];
  }

  void sing()
  {
    for (int i = 0; i < _farm.size(); i++)
    {
      cout << "Old McDonald had a farm, E-I-E-I-O\n";
      /* TODO: Add the rest of the lyrics here... */
      cout << "And on his farm he had a " << _farm[i]->getName() << ", E-I-E-I-O\n";
      cout << "With a " << _farm[i]->getSound() << " " << _farm[i]->getSound() << " here "; 
      cout << "and a " << _farm[i]->getSound() << " " << _farm[i]->getSound() << " there\n";
      cout << _farm[i]->getSound() << " here " << _farm[i]->getSound() << " there, "; 
      cout << "everywhere " << _farm[i]->getSound() << " " << _farm[i]->getSound() << endl; 
      cout << "Old McDonald had a farm, E-I-E-I-O\n";
      cout << endl; 
    }
  }
};

int main () {
  OldMcDonald().sing(); 

  return 0; 
}