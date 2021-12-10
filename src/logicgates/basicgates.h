#ifndef BASICGATES_H
#define BASICGATES_H

#include "logicgate.h"

class AndGate : public LogicGate
{
private:
    void operate();
};

class OrGate : public LogicGate
{
private:
    void operate();
};

class NotGate : public LogicGate
{
private:
    void operate();
};

#endif
