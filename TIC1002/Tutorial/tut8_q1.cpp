#include <iostream>
using namespace std;

class Animal
{
private:
    string _name;  // e.g. Cow
    string _sound; // e.g. Moo

public:
    Animal(string name, string sound)
    {
        _name = name;
        _sound = sound;
    }

    string getName() { return _name; }

    string getSound() { return _sound; }
};

class Flyer : public Animal
{
protected:
    bool _isFlying;

public:
    Flyer(string name, string sound)
        : Animal(name, sound ), _isFlying(false) {}

    string getSound()
    {
        if (_isFlying)
            return "flap";
        else
            return Animal::getSound();
    }
    void fly() { _isFlying = true; }

    void stop() { _isFlying = false; }
};

class Glider : public Flyer
{
private:
    bool _isGliding;

public:
    Glider(string name, string sound)
        : Flyer(name, sound), _isGliding(false) {}

    void glide()
    {
        if (_isFlying)
            _isGliding = true;
    }

    void stop()
    {
        _isFlying = false;
        _isGliding = false;
    }

    string getSound()
    {
        if (_isGliding)
            return "woosh";
        else
            return getSound();
    }
};
