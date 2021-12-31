#include <iostream>
#include <math.h>
#include <chrono>

#include "../src/logicgates/logicgates.hpp"

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

     auto liveInputs = vector<LogicState *>(inputsCount);
     for (auto &&liveInput : liveInputs)
          liveInput = new LogicState;

     gate.setInputs(liveInputs);

     for (int i = inputsCount - 1; i >= 0; i--)
          cout << "IN" << i + 1 << "\t";
     cout << "OUT\t";

     cout << "EXECUTION TIME" << endl;

     for (int i = 0; i < binaryComb; i++)
     {
          vector<bool> inputs = to_binary(inputsCount, i);

          auto start = chrono::high_resolution_clock::now();

          for (int j = 0; j < inputsCount; j++)
               liveInputs.at(j)->setValue(inputs.at(j));

          auto stop = chrono::high_resolution_clock::now();

          for (int i = inputsCount - 1; i >= 0; i--)
               cout << " " << inputs.at(i) << "\t";
          cout << " " << gate.getOutput()->getValue() << "\t";

          auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
          cout << duration.count() << " ns" << endl;
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
