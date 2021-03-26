#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Resumer
{
public:
    virtual shared_ptr<Resumer> clone() = 0;
};
class Resume : public Resumer
{
private:
    string name;
    int age;

public:
    Resume(string name, int age) : name(name), age(age) {}
    void setAge(int age) { this->age = age; }
    shared_ptr<Resumer> clone() override
    {
        return shared_ptr<Resumer>(new Resume(*this));
    }
};
