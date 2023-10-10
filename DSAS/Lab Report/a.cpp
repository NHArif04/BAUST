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