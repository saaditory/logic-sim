#ifndef BASICGATES_H
#define BASICGATES_H

#include "logicgate.h"

class AndGate : public LogicGate
{
private:
    void operate();

public:
    AndGate();
};

class OrGate : public LogicGate
{
private:
    void operate();

public:
    OrGate();
};

class NotGate : public LogicGate
{
private:
    void operate();

public:
    NotGate();
};

#endif
