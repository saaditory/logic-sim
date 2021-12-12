#ifndef DERIVEDGATES_H
#define DERIVEDGATES_H

#include "basicgates.h"

class NandGate : public LogicGate
{
private:
    AndGate andGate;
    NotGate notGate;

    void init();
    void operate();
};

class NorGate : public LogicGate
{
private:
    OrGate orGate;
    NotGate notGate;

    void init();
    void operate();
};

class Xor2Gate : public LogicGate
{
private:
    NotGate notGateA, notGateB;
    AndGate andGateA, andGateB;
    OrGate orGate;

    void init();
    void operate();
};

class XorGate : public LogicGate
{
private:
    vector<Xor2Gate> xor2Gates;

    void init();
    void operate();
};

class XnorGate : public LogicGate
{
private:
    XorGate xorGate;
    NotGate notGate;

    void init();
    void operate();
};

#endif
