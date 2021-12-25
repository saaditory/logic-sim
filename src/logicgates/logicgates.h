#ifndef LOGICGATES_H
#define LOGICGATES_H

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

class NandGate : public LogicGate
{
private:
    void operate();
};

class NorGate : public LogicGate
{
private:
    void operate();
};

class XorGate : public LogicGate
{
private:
    void operate();
};

class XnorGate : public LogicGate
{
private:
    void operate();
};

#endif
