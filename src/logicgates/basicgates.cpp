#include "basicgates.h"

void AndGate::operate()
{
    bool output = true;
    for (bool input : getInputs())
        output &= input;
    setOutput(output);
}
void AndGate::setObserver(Observer *_) { LogicGate::setObserver(this); }

void OrGate::operate()
{
    bool output = false;
    for (bool input : getInputs())
        output |= input;
    setOutput(output);
}
void OrGate::setObserver(Observer *_) { LogicGate::setObserver(this); }

void NotGate::operate()
{
    setOutput(!getInputs().at(0));
}
void NotGate::setObserver(Observer *_) { LogicGate::setObserver(this); }
