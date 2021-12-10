#ifndef LOGICGATE_H
#define LOGICGATE_H

#include <vector>

#include "../../lib/livedata-cpp/include/livedata/livedata.h"

using namespace std;

class LogicGate : private LiveData<bool>, private Observer<bool>
{
private:
    vector<LiveData<bool>> mInputs;

    void updateInputs(vector<bool>);

protected:
    void onChanged(bool);

    virtual void init(vector<bool>);
    virtual void operate() {}

    void setOutput(bool);

public:
    void setInputs(vector<bool>);

    vector<bool> getInputs();
    bool getOutput();
};

#endif
