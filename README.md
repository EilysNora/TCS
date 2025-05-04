# DFA String Acceptance Checker

Users can define a DFA and test input strings for acceptance or rejection using this C++-based deterministic finite automaton simulator.

## ✨ Include: 

- User-defined states, alphabet size, and transition table
- Supports custom start and final states
- Input trace of DFA execution
- Accept/reject result output


## 📥 Input Format

Each prompt expects input in the following order:

- **Number of states** – Total number of DFA states (e.g., `3`)
- **Alphabet size** – Number of input symbols (e.g., `2` for binary)
- **Transition table** – For each state, specify the next state for each input symbol (entered row-wise)
- **Start state** – Index of the start state (e.g., `0`)
- **Final states** – Space-separated list of accepting state indices (e.g., `2`)
- **Input string** – String composed of digits from `0` to `alphabetSize - 1` (e.g., `0101`)

## 📌 Example

```plaintext
Enter number of states: 3
Enter alphabet size (e.g., 2 for binary): 2
Enter the transition table:
State 0: 1 2
State 1: 0 2
State 2: 2 2
Enter start state (0 to 2): 0
Enter number of final states: 1
Enter final states: 2
Enter input string (digits 0 to 1): 0101

Trace: 0 -> 1 -> 0 -> 1 -> 0
Result: REJECTED
```
## Code Explanation
This C++ program simulates a Deterministic Finite Automaton (DFA). It takes user input for the number of states, alphabet size, transition table, start state, final states, and an input string, then simulates the DFA's execution step-by-step to determine whether the input string is accepted or rejected.

## 1. Input Details
The program starts by prompting the user for several inputs:

Number of States: This defines how many states the DFA will have (e.g., 3 means the DFA has 3 states labeled 0, 1, and 2).

Alphabet Size: The program supports a binary alphabet (e.g., 0 and 1 for binary) or any other custom alphabet size (e.g., 2 for binary, 3 for ternary).

Transition Table: A table where each state has a transition for each possible symbol in the alphabet. This input is entered row by row. 
## 📌 Example

```plaintext
State 0: 1 2
State 1: 0 2
State 2: 2 2

```
**This means, for instance:

If the DFA is in State 0 and reads 0, it moves to State 1.

If it's in State 1 and reads 1, it moves to State 2, and so on.
Start State: This is the state where the DFA begins (usually 0).

Final States: These are the states in which the DFA will accept the input. If the DFA ends in a final state, the input is considered accepted.

Input String: The string that the DFA will process. This string must consist of symbols from the DFA's alphabet (e.g., 0101 for a binary DFA).
## 2. Transition Simulation
After collecting the input, the program initializes the DFA and starts processing the input string:

State Transitions: The DFA begins at the start state. For each symbol in the input string, the program looks up the current state in the transition table and follows the corresponding transition.

Current State Tracking: As the DFA processes each symbol, it keeps track of the current state, printing the trace of states as it processes the input. For example:
## 📌 Example

```plaintext
Trace: 0 -> 1 -> 0 -> 1 -> 0

```
This shows how the DFA moves through states as it processes the input string (0101).
## 3. Acceptance or Rejection
Once the DFA has processed all symbols in the input string, the program checks whether the DFA's current state is a final (accepting) state:

If the current state is one of the final states, the input string is accepted, and the program outputs:
```plaintext
Result: ACCEPTED

```
Otherwise, the input string is rejected, and the program outputs:
```plaintext
Result: REJECTED
```
## 4. Edge Cases
The program does not handle invalid inputs, such as:

An alphabet symbol that is not in the range 0 to alphabetSize - 1.

A state in the transition table with an invalid transition.

The user must ensure the inputs follow the correct format and provide valid values.

