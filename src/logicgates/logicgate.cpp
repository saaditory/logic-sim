#include "logicgate.h"

void LogicGate::init()
{
    for (auto &&input : getInputs())
        input->observe(this);
}

void LogicGate::onChanged(bool _) { operate(); }

void LogicGate::setInputs(vector<LiveData<bool> *> inputs)
{
    for (auto &&input : inputs)
        mInputs.push_back(input);

    init();
    operate();
}
void LogicGate::setOutput(bool state) { setValue(state); }

vector<LiveData<bool> *> LogicGate::getInputs() { return mInputs; }
LiveData<bool> *LogicGate::getOutput() { return this; }
