#include "logicgates.h"

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

void NandGate::operate()
{
    bool output = true;
    for (auto &&input : getInputs())
        output &= input->getValue();
    setOutput(!output);
}

void NorGate::operate()
{
    bool output = false;
    for (auto &&input : getInputs())
        output |= input->getValue();
    setOutput(!output);
}

void XorGate::operate()
{
    bool output = false;
    for (auto &&input : getInputs())
        output ^= input->getValue();
    setOutput(output);
}

void XnorGate::operate()
{
    bool output = false;
    for (auto &&input : getInputs())
        output ^= input->getValue();
    setOutput(!output);
}
