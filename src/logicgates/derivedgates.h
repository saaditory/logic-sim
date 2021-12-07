#ifndef DERIVEDGATES_H
#define DERIVEDGATES_H

#include "basicgates.h"

class NandGate : public LogicGate
{
private:
    AndGate andGate;
    NotGate notGate;

    void operate();

public:
    NandGate();
};

class NorGate : public LogicGate
{
private:
    OrGate orGate;
    NotGate notGate;

    void operate();

public:
    NorGate();
};

class Xor2Gate : public LogicGate
{
private:
    NotGate notGate1, notGate2;
    AndGate andGate1, andGate2;
    OrGate orGate;

    void operate();

public:
    Xor2Gate();
};

class XorGate : public LogicGate
{
private:
    vector<Xor2Gate> xor2Gates;

    void init(vector<bool>);
    void operate();

public:
    XorGate();
};

class XnorGate : public LogicGate
{
private:
    XorGate xorGate;
    NotGate notGate;

    void operate();

public:
    XnorGate();
};

#endif
