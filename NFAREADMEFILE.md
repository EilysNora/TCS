# NFA Simulator with λ-Transitions

Users can define an NFA (with epsilon transitions) and compute extended transition functions δ* using this C++-based nondeterministic finite automaton simulator.

## ✨ Features
- **Complete NFA Configuration**: Define states, alphabet, and transition rules
- **ε-Transitions Support**: Handles lambda (epsilon) transitions
- **Extended Transition Functions**: Computes both:
  - `δ*(q, a) = λ-closure(move(λ-closure(q), a))` 
  - `δ*(T, a) = λ-closure(move(λ-closure(T), a))`
- **Detailed Computation Tracing**: Shows each step of λ-closure and move operations
- **Interactive Testing**: Continuously evaluate δ* until exit

## 📥 Input Format
The program guides you through these inputs:

1. **Number of States** (e.g., 3 for q0-q2)  
2. **Alphabet Symbols** (space-separated, include 'epsilon')  
3. **Transitions** (one per line):  
   `<from_state> <symbol> <to_state>`  
   Example: `0 a 1` or `1 epsilon 2`  
4. **Test Cases**:  
   `<state> <symbol>` to compute δ*  

## 📌 Example Session
```text
=== NFA Initialization ===
Enter number of states: 3
Enter alphabet symbols: a epsilon

Enter transitions:
0 a 1
0 epsilon 2
1 a 0
1 epsilon 2
done

=== Testing ===
Test case: 0 a
Computing δ*(0, a):
λ-closure(0) = {0 2}
move({0 2}, a) = {1}
λ-closure({1}) = {1 2}
Result: {0 1 2}

Test case: quit
