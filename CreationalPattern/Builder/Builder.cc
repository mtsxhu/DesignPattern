#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

class PersonBuilder
{
public:
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildArmLeft() = 0;
    virtual void BuildArmRight() = 0;
    virtual void BuildLegLeft() = 0;
    virtual void BuildLegRight() = 0;
};
class PersonThinBuilder : public PersonBuilder
{
private:
    /* data */
public:
    void BuildHead() override { cout << "build thin person head" << endl; }
    void BuildBody() override { cout << "build thin person body" << endl; }
    void BuildArmLeft() override { cout << "build thin person left arm" << endl; }
    void BuildArmRight() override { cout << "build thin person right arm" << endl; }
    void BuildLegLeft() override { cout << "build thin person left leg" << endl; }
    void BuildLegRight() override { cout << "build thin person right leg" << endl; }
};
class PersonFatBuilder : public PersonBuilder
{
private:
    /* data */
public:
    void BuildHead() override { cout << "build fat person head" << endl; }
    void BuildBody() override { cout << "build fat person body" << endl; }
    void BuildArmLeft() override { cout << "build fat person left arm" << endl; }
    void BuildArmRight() override { cout << "build fat person right arm" << endl; }
    void BuildLegLeft() override { cout << "build fat person left leg" << endl; }
    void BuildLegRight() override { cout << "build fat person right leg" << endl; }
};

class PersonDirector
{
public:
    void buildPerson(PersonBuilder &p)
    {
        p.BuildHead();
        p.BuildBody();
        p.BuildArmLeft();
        p.BuildArmRight();
        p.BuildLegLeft();
        p.BuildLegRight();
    }
};
