#ifndef BASICGATES_H
#define BASICGATES_H

#include "logicgate.h"

class AndGate : public LogicGate
{
private:
    void operate();
    void setObserver(Observer *);
};

class OrGate : public LogicGate
{
private:
    void operate();
    void setObserver(Observer *);
};

class NotGate : public LogicGate
{
private:
    void operate();
    void setObserver(Observer *);
};

#endif
