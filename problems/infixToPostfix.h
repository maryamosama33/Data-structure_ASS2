
#ifndef DATA_STRUCTURE_ASS2_INFIXTOPOSTFIX_H
#define DATA_STRUCTURE_ASS2_INFIXTOPOSTFIX_H
#include<bits/stdc++.h>
#include"Stack.h"
using namespace std;

int getPrecedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

string infixToPostfix(string infix) {
    Stack<char> opStack;
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            opStack.push(ch);
        }
        else if (ch == ')') {
            while (!opStack.isEmpty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.isEmpty() && opStack.top() == '(') {
                opStack.pop();
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!opStack.isEmpty() && getPrecedence(opStack.top()) >= getPrecedence(ch)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(ch);
        }
    }
    while (!opStack.isEmpty()) {
        postfix += opStack.top();
        opStack.pop();
    }
    return postfix;
}
#endif //DATA_STRUCTURE_ASS2_INFIXTOPOSTFIX_H
