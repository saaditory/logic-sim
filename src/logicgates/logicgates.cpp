#include "logicgates.hpp"

#define GATE_AND "AND"
#define GATE_OR "OR"
#define GATE_NOT "NOT"
#define GATE_NAND "NAND"
#define GATE_NOR "NOR"
#define GATE_XOR "XOR"
#define GATE_XNOR "XNOR"

void AndGate::operate()
{
    bool state = true;
    for (auto &&input : getInputs())
        state &= input->getValue();
    setOutput(state);
}
AndGate::AndGate() { setName(GATE_AND); }

void OrGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state |= input->getValue();
    setOutput(state);
}
OrGate::OrGate() { setName(GATE_OR); }

void NotGate::operate()
{
    setOutput(!getInputs().at(0)->getValue());
}
NotGate::NotGate() { setName(GATE_NOT); }

void NandGate::operate()
{
    bool state = true;
    for (auto &&input : getInputs())
        state &= input->getValue();
    setOutput(!state);
}
NandGate::NandGate() { setName(GATE_NAND); }

void NorGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state |= input->getValue();
    setOutput(!state);
}
NorGate::NorGate() { setName(GATE_NOR); }

void XorGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state ^= input->getValue();
    setOutput(state);
}
XorGate::XorGate() { setName(GATE_XOR); }

void XnorGate::operate()
{
    bool state = false;
    for (auto &&input : getInputs())
        state ^= input->getValue();
    setOutput(!state);
}
XnorGate::XnorGate() { setName(GATE_XNOR); }

LogicGate *GateFactory::getGate(std::string name)
{
    if (GATE_AND == name)
        return new AndGate;
    else if (GATE_OR == name)
        return new OrGate;
    else if (GATE_NOT == name)
        return new NotGate;
    else if (GATE_NAND == name)
        return new NandGate;
    else if (GATE_NOR == name)
        return new NorGate;
    else if (GATE_XOR == name)
        return new XorGate;
    else if (GATE_XNOR == name)
        return new XnorGate;
    else
        return (LogicGate *)new LogicState;
}

std::vector<LogicGate *> GateFactory::getGates(std::vector<JsonGate> jsonGates,
                                               std::vector<LogicState *> &inputs)
{
    std::vector<LogicGate *> gates;

    for (auto &&jsonGate : jsonGates)
    {
        LogicGate *gate = getGate(jsonGate.getName());
        if (JSON_INPUT_DEFAULT_NAME != gate->getName())
        {
            auto gates = getGates(jsonGate.getInputs(), inputs);

            std::vector<LogicState *> states;
            for (auto &&gate : gates)
                states.push_back(gate);

            gate->setInputs(states);
        }
        else
        {
            gate->setName(jsonGate.getName());

            bool is_existing = false;
            for (auto &&input : inputs)
                if (input->getName() == gate->getName())
                {
                    is_existing = true;
                    gate = (LogicGate *)input;
                    break;
                }

            if (!is_existing)
                inputs.push_back(gate);
        }
        gates.push_back(gate);
    }

    return gates;
}
