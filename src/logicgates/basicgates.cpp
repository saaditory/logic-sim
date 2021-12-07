#include "basicgates.h"

void AndGate::operate()
{
    bool output = true;
    for (bool input : getInputs())
        output &= input;
    setOutput(output);
}
AndGate::AndGate() { setObserver(this); };

void OrGate::operate()
{
    bool output = false;
    for (bool input : getInputs())
        output |= input;
    setOutput(output);
}
OrGate::OrGate() { setObserver(this); };

void NotGate::operate()
{
    setOutput(!getInputs().at(0));
}
NotGate::NotGate() { setObserver(this); };

