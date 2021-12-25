#include "logicgates.hpp"

void AndGate::operate()
{
    bool state = true;
    for (auto &&input : getInputs())
        state &= input->getValue();
    setOutput(state);
}

void OrGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state |= input->getValue();
    setOutput(state);
}

void NotGate::operate()
{
    setOutput(!getInputs().at(0)->getValue());
}

void NandGate::operate()
{
    bool state = true;
    for (auto &&input : getInputs())
        state &= input->getValue();
    setOutput(!state);
}

void NorGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state |= input->getValue();
    setOutput(!state);
}

void XorGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state ^= input->getValue();
    setOutput(state);
}

void XnorGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state ^= input->getValue();
    setOutput(!state);
}
