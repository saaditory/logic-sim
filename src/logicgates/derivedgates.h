#ifndef DERIVEDGATES_H
#define DERIVEDGATES_H

#include "basicgates.h"

class NandGate : public LogicGate
{
private:
    AndGate andGate;
    NotGate notGate;

    void operate();
};

class NorGate : public LogicGate
{
private:
    OrGate orGate;
    NotGate notGate;

    void operate();
};

class Xor2Gate : public LogicGate
{
private:
    NotGate notGate1, notGate2;
    AndGate andGate1, andGate2;
    OrGate orGate;

    void operate();
};

class XorGate : public LogicGate
{
private:
    vector<Xor2Gate> xor2Gates;

    void init(vector<bool>);
    void operate();
};

class XnorGate : public LogicGate
{
private:
    XorGate xorGate;
    NotGate notGate;

    void operate();
};

#endif
