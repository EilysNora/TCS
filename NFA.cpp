#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int numStates, alphabetSize;
    cout << "Enter number of states: ";
    cin >> numStates;

    cout << "Enter alphabet size (e.g., 2 for binary): ";
    cin >> alphabetSize;

    vector<vector<int>> transition(numStates, vector<int>(alphabetSize));

    cout << "Enter the transition table:\n";
    cout << "(Each row corresponds to a state, and each column to a symbol)\n";
    for (int i = 0; i < numStates; ++i) {
        cout << "State " << i << ": ";
        for (int j = 0; j < alphabetSize; ++j) {
            cin >> transition[i][j];
        }
    }

    int startState;
    cout << "Enter start state (0 to " << numStates - 1 << "): ";
    cin >> startState;

    int numFinalStates;
    cout << "Enter number of final states: ";
    cin >> numFinalStates;

    set<int> finalStates;
    cout << "Enter final states: ";
    for (int i = 0; i < numFinalStates; ++i) {
        int f;
        cin >> f;
        finalStates.insert(f);
    }

    string input;
    cout << "Enter input string (digits 0 to " << alphabetSize - 1 << "): ";
    cin >> input;

    int currentState = startState;
    cout << "\nTrace: ";
    cout << currentState;

    for (char ch : input) {
        int symbol = ch - '0';
        if (symbol < 0 || symbol >= alphabetSize) {
            cout << "\nInvalid symbol: " << ch << "\n";
            return 1;
        }
        currentState = transition[currentState][symbol];
        cout << " -> " << currentState;
    }

    if (finalStates.count(currentState)) {
        cout << "\nResult: ACCEPTED\n";
    } else {
        cout << "\nResult: REJECTED\n";
    }

    return 0;
}
