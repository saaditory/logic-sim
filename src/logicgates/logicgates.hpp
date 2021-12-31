#ifndef LOGICGATES_HPP
#define LOGICGATES_HPP

#include "logicgate.hpp"

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

class NandGate : public LogicGate
{
private:
    void operate();

public:
    NandGate();
};

class NorGate : public LogicGate
{
private:
    void operate();

public:
    NorGate();
};

class XorGate : public LogicGate
{
private:
    void operate();

public:
    XorGate();
};

class XnorGate : public LogicGate
{
private:
    void operate();

public:
    XnorGate();
};

class GateFactory
{
public:
    static LogicGate *getGate(std::string);
    static std::vector<LogicGate *> getGates(std::vector<JsonGate>, std::vector<LogicState *> &);
};

#endif
