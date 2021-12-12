#include "basicgates.h"

void AndGate::operate()
{
    bool output = true;
    for (auto &&input : getInputs())
        output &= input->getValue();
    setOutput(output);
}

void OrGate::operate()
{
    bool output = false;
    for (auto &&input : getInputs())
        output |= input->getValue();
    setOutput(output);
}

void NotGate::operate()
{
    setOutput(!getInputs().at(0)->getValue());
}
