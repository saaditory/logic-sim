#include "derivedgates.h"

void NandGate::init()
{
    andGate.setInputs(getInputs());
    notGate.setInputs(vector<LiveData<bool> *>{andGate.getOutput()});
    notGate.getOutput()->observe(this);
}
void NandGate::operate() { setOutput(notGate.getOutput()->getValue()); }

void NorGate::init()
{
    orGate.setInputs(getInputs());
    notGate.setInputs(vector<LiveData<bool> *>{orGate.getOutput()});
    notGate.getOutput()->observe(this);
}
void NorGate::operate() { setOutput(notGate.getOutput()->getValue()); }

void Xor2Gate::init()
{
    notGateA.setInputs(vector<LiveData<bool> *>{getInputs().at(0)});
    notGateB.setInputs(vector<LiveData<bool> *>{getInputs().at(1)});
    andGateA.setInputs(vector<LiveData<bool> *>{getInputs().at(0), notGateB.getOutput()});
    andGateB.setInputs(vector<LiveData<bool> *>{notGateA.getOutput(), getInputs().at(1)});
    orGate.setInputs(vector<LiveData<bool> *>{andGateA.getOutput(), andGateB.getOutput()});
    orGate.getOutput()->observe(this);
}
void Xor2Gate::operate() { setOutput(orGate.getOutput()->getValue()); }

void XorGate::init()
{
    int gateCount = getInputs().size() - 1;
    xor2Gates = vector<Xor2Gate>(gateCount);
    for (int gatePos = 0; gatePos < gateCount; gatePos++)
        xor2Gates.at(gatePos)
            .setInputs((0 != gatePos)
                           ? vector<LiveData<bool> *>{xor2Gates.at(gatePos - 1).getOutput(),
                                                      getInputs().at(gatePos + 1)}
                           : vector<LiveData<bool> *>{getInputs().at(gatePos),
                                                      getInputs().at(gatePos + 1)});
    xor2Gates.at(gateCount - 1).getOutput()->observe(this);
}
void XorGate::operate() { setOutput(xor2Gates.at(getInputs().size() - 2).getOutput()->getValue()); }

void XnorGate::init()
{
    xorGate.setInputs(getInputs());
    notGate.setInputs(vector<LiveData<bool> *>{xorGate.getOutput()});
    notGate.getOutput()->observe(this);
}
void XnorGate::operate() { setOutput(notGate.getOutput()->getValue()); }
