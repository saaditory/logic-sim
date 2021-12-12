#include "logicgate.h"

void LogicGate::init()
{
    for (auto &&input : getInputs())
        input->observe(this);
}

void LogicGate::onChanged(bool _) { operate(); }

void LogicGate::setInputs(vector<LiveData<bool> *> inputs)
{
    mInputs.clear();
    mInputs = inputs;

    init();
    operate();
}
void LogicGate::setOutput(bool value) { setValue(value); }

vector<LiveData<bool> *> LogicGate::getInputs() { return mInputs; }
LiveData<bool> *LogicGate::getOutput() { return this; }
