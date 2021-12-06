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

     for (int i = 0; i < inputsCount; i++)
          cout << "IN" << i + 1 << "\t";
     cout << "OUT" << endl;

     for (int i = 0; i < binaryComb; i++)
     {
          vector<bool> inputs = to_binary(inputsCount, i);

          gate.setInputs(inputs);

          for (int i = inputsCount - 1; i >= 0; i--)
               cout << " " << inputs.at(i) << "\t";
          cout << " " << gate.getOutput() << endl;
     }
}

int main()
{
     AndGate andGate;
     OrGate orGate;
     NotGate notGate;
     NandGate nandGate;
     NorGate norGate;
     XorGate xorGate;
     XnorGate xnorGate;

     cout << "AND Gate:" << endl;
     printTruthTable(andGate);
     cout << endl
          << "OR Gate:" << endl;
     printTruthTable(orGate);
     cout << endl
          << "NOT Gate:" << endl;
     printTruthTable(notGate);
     cout << endl
          << "NAND Gate:" << endl;
     printTruthTable(nandGate);
     cout << endl
          << "NOR Gate:" << endl;
     printTruthTable(norGate);
     cout << endl
          << "XOR Gate:" << endl;
     printTruthTable(xorGate);
     cout << endl
          << "XNOR Gate:" << endl;
     printTruthTable(xnorGate);

     return 0;
}
