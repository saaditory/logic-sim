#ifndef LOGICGATE_H
#define LOGICGATE_H

#include <vector>

#include "../../lib/livedata-cpp/include/livedata/livedata.h"

using namespace std;

class LogicGate : public Observer<bool>
{
private:
    vector<LiveData<bool>> mInputs;
    LiveData<bool> mOutput;

protected:
    void onChanged(bool);

    virtual void init(int);
    virtual void operate() {}
    virtual void setObserver(Observer *);

    void setOutput(bool);

public:
    void setInputs(vector<bool>);

    vector<bool> getInputs();
    bool getOutput();
};

#endif
