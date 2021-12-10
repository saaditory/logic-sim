#include "basicgates.h"

void AndGate::operate()
{
    bool output = true;
    for (bool input : getInputs())
        output &= input;
    setOutput(output);
}

void OrGate::operate()
{
    bool output = false;
    for (bool input : getInputs())
        output |= input;
    setOutput(output);
}

void NotGate::operate()
{
    setOutput(!getInputs().at(0));
}

