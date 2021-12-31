#include "logicgate.hpp"

void LogicGate::init()
{
    for (auto &&input : getInputs())
        input->observe(this);
}

void LogicGate::onChanged(bool _) { operate(); }

void LogicGate::setInputs(std::vector<LogicState *> inputs)
{
    for (auto &&input : inputs)
        mInputs.push_back(input);

    init();
    operate();

    JsonGate::setInputs(inputs);
}
void LogicGate::setOutput(bool state) { setValue(state); }

std::vector<LogicState *> LogicGate::getInputs() { return mInputs; }
LogicState *LogicGate::getOutput() { return this; }
