#include "logicgate.h"

void LogicGate::init(int inputCount)
{
    mInputs.clear();
    mInputs = vector<LiveData<bool>>(inputCount);
    for (LiveData<bool> &input : mInputs)
        input.setValue(false);

    operate();
    setObserver(this);
}
void LogicGate::onChanged(bool _) { operate(); }
void LogicGate::setObserver(Observer *observer)
{
    for (LiveData<bool> &input : mInputs)
        input.observe(observer);
}
void LogicGate::setOutput(bool value) { mOutput.setValue(value); }

void LogicGate::setInputs(vector<bool> values)
{
    init(values.size());
    for (int i = 0; i < values.size(); i++)
        mInputs.at(i).setValue(values.at(i));
}

vector<bool> LogicGate::getInputs()
{
    vector<bool> inputs;
    for (LiveData<bool> &input : mInputs)
        inputs.push_back(input.getValue());

    return inputs;
}
bool LogicGate::getOutput() { return mOutput.getValue(); }
