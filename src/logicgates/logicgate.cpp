#include "logicgate.h"

void LogicGate::init(vector<bool> inputs)
{
    mInputs.clear();
    for (bool input : inputs)
    {
        mInputs.push_back(LiveData<bool>(input));
        mInputs.back().observe(mObserver);
    }
    operate();
}
void LogicGate::updateInputs(vector<bool> inputs)
{
    for (int i = 0; i < inputs.size(); i++)
        mInputs.at(i).setValue(inputs.at(i));
}

void LogicGate::setObserver(Observer *observer) { mObserver = observer; }
void LogicGate::onChanged(bool _) { operate(); }

void LogicGate::setInputs(vector<bool> values)
{
    (values.size() != mInputs.size())
        ? init(values)
        : updateInputs(values);
}
void LogicGate::setOutput(bool value) { mOutput.setValue(value); }

vector<bool> LogicGate::getInputs()
{
    vector<bool> inputs;
    for (LiveData<bool> &input : mInputs)
        inputs.push_back(input.getValue());

    return inputs;
}
bool LogicGate::getOutput() { return mOutput.getValue(); }
