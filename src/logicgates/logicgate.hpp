#ifndef LOGICGATE_HPP
#define LOGICGATE_HPP

#include <vector>

#include "../../lib/livedata-cpp/include/livedata/livedata.hpp"

using namespace std;

class LogicGate : public LiveData<bool>, protected Observer<bool>
{
private:
    vector<LiveData<bool> *> mInputs = vector<LiveData<bool> *>();

protected:
    void onChanged(bool);

    virtual void init();
    virtual void operate() = 0;

    void setOutput(bool);

public:
    void setInputs(vector<LiveData<bool> *>);

    vector<LiveData<bool> *> getInputs();
    LiveData<bool> *getOutput();
};

#endif
