# Expression Evaluation in Postfix and Prefix Notations
---
## Objectives:
1. Evaluate arithmetic expressions in postfix and prefix notations.
2. Utilize stack data structures for expression evaluation.
3. Compare the evaluation processes for postfix and prefix notations.
4. Demonstrate the efficiency of stack-based evaluation.
---
## Introduction:
This report explores the evaluation of arithmetic expressions in postfix and prefix notations using stack data structures. It aims to understand the algorithms and processes involved in evaluating expressions in these notations.
---
## Description:
### Postfix Notation:
- **Expression Format:** Operators follow their operands.
- **Evaluation Process:**
  1. Initialize an empty stack.
  2. Scan the expression from left to right.
  3. Push operands onto the stack.
  4. When an operator is encountered, pop operands from the stack, perform the operation, and push the result back.
  5. The final result is the top element of the stack.
---
### Prefix Notation:
- **Expression Format:** Operators precede their operands.
- **Evaluation Process:**
  1. Initialize an empty stack.
  2. Scan the expression from right to left.
  3. Push operands onto the stack.
  4. When an operator is encountered, pop operands from the stack, perform the operation, and push the result back.
  5. The final result is the top element of the stack.
---
## Source Code:
```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evalPostfix(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else if (c != ' ') {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            s.push(c == '+' ? op1 + op2 : c == '-' ? op1 - op2 : c == '*' ? op1 * op2 : op1 / op2);
        }
    }
    return s.top();
}

int evalPrefix(string exp) {
    stack<int> s;
    for (int i = exp.size() - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c)) s.push(c - '0');
        else if (c != ' ') {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            s.push(c == '+' ? op1 + op2 : c == '-' ? op1 - op2 : c == '*' ? op1 * op2 : op1 / op2);
        }
    }
    return s.top();
}

int main() {
    string postfix = "23*5+";
    string prefix = "+*235";

    int postfixResult = evalPostfix(postfix);
    int prefixResult = evalPrefix(prefix);

    cout << "Postfix: " << postfixResult << endl;
    cout << "Prefix: " << prefixResult << endl;

    return 0;
}
```

---
## Sample Output:

- Postfix: 11
- Prefix: 11

---
## Discussion:
The report demonstrates the evaluation of arithmetic expressions in postfix and prefix notations using stack-based algorithms. Both postfix and prefix notations can be efficiently evaluated using stacks, and the results match the expected values.

---
## Conclusion:
Stack-based evaluation simplifies arithmetic expression evaluation in postfix and prefix notations. Postfix notation, with operators following operands, is commonly used in practice due to its efficiency and simplicity in parsing. Prefix notation, with operators preceding operands, has its advantages but is less commonly used.