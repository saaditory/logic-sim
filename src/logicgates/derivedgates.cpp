#include "derivedgates.h"

void NandGate::operate()
{
    andGate.setInputs(getInputs());
    notGate.setInputs(vector<bool>{andGate.getOutput()});
    setOutput(notGate.getOutput());
}

void NorGate::operate()
{
    orGate.setInputs(getInputs());
    notGate.setInputs(vector<bool>{orGate.getOutput()});
    setOutput(notGate.getOutput());
}

void Xor2Gate::operate()
{
    notGate1.setInputs(vector<bool>{getInputs().at(0)});
    notGate2.setInputs(vector<bool>{getInputs().at(1)});
    andGate1.setInputs(vector<bool>{getInputs().at(0), notGate2.getOutput()});
    andGate2.setInputs(vector<bool>{notGate1.getOutput(), getInputs().at(1)});
    orGate.setInputs(vector<bool>{andGate1.getOutput(), andGate2.getOutput()});
    setOutput(orGate.getOutput());
}

void XorGate::init(vector<bool> inputs)
{
    xor2Gates = vector<Xor2Gate>(inputs.size() - 1);
    LogicGate::init(inputs);
}
void XorGate::operate()
{
    int gateCount = getInputs().size() - 1;
    for (int gatePos = 0; gatePos < gateCount; gatePos++)
    {
        xor2Gates.at(gatePos).setInputs((0 != gatePos)
                                            ? vector<bool>{xor2Gates.at(gatePos - 1).getOutput(),
                                                           getInputs().at(gatePos + 1)}
                                            : vector<bool>{getInputs().at(gatePos),
                                                           getInputs().at(gatePos + 1)});
    }
    setOutput(xor2Gates.at(gateCount - 1).getOutput());
}

void XnorGate::operate()
{
    xorGate.setInputs(getInputs());
    notGate.setInputs(vector<bool>{xorGate.getOutput()});
    setOutput(notGate.getOutput());
}
