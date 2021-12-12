#include <iostream>
#include <bits/stdc++.h>

#include "../src/logicgates/logicgates.h"

using namespace std;

vector<bool> to_binary(int bits, int value)
{
     vector<bool> result(bits, 0);
     for (int i = 0; value > 0; i++)
     {
          result.at(i) = value % 2;
          value /= 2;
     }
     return result;
}

void printTruthTable(LogicGate &gate, int inputsCount = 2)
{
     int binaryComb = pow(2, inputsCount);

     auto liveInputs = vector<LiveData<bool>>(inputsCount, new LiveData<bool>);

     vector<LiveData<bool> *> liveInputsPtr;
     for (auto &&liveInput : liveInputs)
          liveInputsPtr.push_back(&liveInput);
     gate.setInputs(liveInputsPtr);

     for (int i = 0; i < inputsCount; i++)
          cout << "IN" << i + 1 << "\t";
     cout << "OUT" << endl;

     for (int i = 0; i < binaryComb; i++)
     {
          vector<bool> inputs = to_binary(inputsCount, i);

          for (int j = 0; j < inputsCount; j++)
               liveInputs.at(j).setValue(inputs.at(j));

          for (int i = inputsCount - 1; i >= 0; i--)
               cout << " " << inputs.at(i) << "\t";
          cout << " " << gate.getOutput()->getValue() << endl;
     }
}

int main()
{
     string labels[] =
         {"AND", "OR", "NOT", "NAND", "NOR", "XOR", "XNOR"};
     LogicGate *gates[] = {new AndGate, new OrGate, new NotGate,
                           new NandGate, new NorGate, new XorGate, new XnorGate};

     for (int i = 0; i < 7; i++)
     {
          cout << labels[i] << " Gate:" << endl;
          printTruthTable(*gates[i]);
          cout << endl;
     }

     return 0;
}
