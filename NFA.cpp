#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// Function to compute the λ-closure of a set of states
unordered_set<int> lambda_closure(const unordered_map<int, unordered_map<string, unordered_set<int>>>& nfa, const unordered_set<int>& states) {
    unordered_set<int> closure = states;
    stack<int> state_stack;

    // Push all states in the closure to the stack
    for (int state : states) {
        state_stack.push(state);
    }

    while (!state_stack.empty()) {
        int state = state_stack.top();
        state_stack.pop();

        // For each epsilon transition ("epsilon"), add the next state to the closure if not already in it
        if (nfa.at(state).find("epsilon") != nfa.at(state).end()) {
            for (int next_state : nfa.at(state).at("epsilon")) {
                if (closure.find(next_state) == closure.end()) {
                    closure.insert(next_state);
                    state_stack.push(next_state);
                }
            }
        }
    }

    return closure;
}

// Function to move from a set of states on a specific input symbol
unordered_set<int> move(const unordered_map<int, unordered_map<string, unordered_set<int>>>& nfa, const unordered_set<int>& states, const string& symbol) {
    unordered_set<int> reachable_states;

    for (int state : states) {
        if (nfa.at(state).find(symbol) != nfa.at(state).end()) {
            reachable_states.insert(nfa.at(state).at(symbol).begin(), nfa.at(state).at(symbol).end());
        }
    }

    return reachable_states;
}

// Function to compute δ*(q, a) = epsilon-closure(move(epsilon-closure(q), a)) for a given state and symbol
unordered_set<int> delta_star(const unordered_map<int, unordered_map<string, unordered_set<int>>>& nfa, int state, const string& symbol) {
    unordered_set<int> closure_q = lambda_closure(nfa, {state});
    unordered_set<int> moved_q = move(nfa, closure_q, symbol);
    return lambda_closure(nfa, moved_q);
}

int main() {
    int num_states, num_transitions;
    cout << "Enter the number of states: ";
    cin >> num_states;

    // Initialize the NFA transition table
    unordered_map<int, unordered_map<string, unordered_set<int>>> nfa;

    cout << "Enter the number of transitions: ";
    cin >> num_transitions;

    cout << "Enter transitions in the format: <state> <symbol> <next_state> (use 'epsilon' for epsilon transitions)" << endl;

    for (int i = 0; i < num_transitions; ++i) {
        int state, next_state;
        string symbol;
        cin >> state >> symbol >> next_state;

        // Add the transition to the NFA table
        nfa[state][symbol].insert(next_state);
    }

    int q, T;
    string symbol;
    
    cout << "Enter the starting state (q): ";
    cin >> q;

    cout << "Enter the target state (T): ";
    cin >> T;

    cout << "Enter the transition symbol (a): ";
    cin >> symbol;

    // Compute δ*(q, a) and δ*(T, a)
    unordered_set<int> delta_q_a = delta_star(nfa, q, symbol);
    unordered_set<int> delta_T_a = delta_star(nfa, T, symbol);

    // Output the results
    cout << "δ*(q, " << symbol << ") = { ";
    for (int state : delta_q_a) {
        cout << state << " ";
    }
    cout << "}" << endl;

    cout << "δ*(T, " << symbol << ") = { ";
    for (int state : delta_T_a) {
        cout << state << " ";
    }
    cout << "}" << endl;

    return 0;
}
