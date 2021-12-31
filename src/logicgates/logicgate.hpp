#ifndef LOGICGATE_HPP
#define LOGICGATE_HPP

#include <vector>
#include <map>

#include "../../lib/livedata-cpp/include/livedata/livedata.hpp"
#include "../json/jsoninput.hpp"

class LogicState : public LiveData<bool>, public JsonGate
{
public:
    LogicState() {}
    LogicState(std::string name) { setName(name); }
};

class LogicGate : public LogicState, protected Observer<bool>
{
private:
    std::vector<LogicState *> mInputs = std::vector<LogicState *>();

protected:
    void onChanged(bool);

    virtual void init();
    virtual void operate() = 0;

    void setOutput(bool);

public:
    void setInputs(std::vector<LogicState *>);

    std::vector<LogicState *> getInputs();
    LogicState *getOutput();
};

#endif
