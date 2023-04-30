

#ifndef DATA_STRUCTURE_ASS2_LONGESTVALIDPARENTHESES_H
#define DATA_STRUCTURE_ASS2_LONGESTVALIDPARENTHESES_H
#include<bits/stdc++.h>
#include"Stack.h"
using namespace std;

int longestValidParentheses(string s) {
    Stack<int> stk;
    int maxLen = 0;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.isEmpty()) {
                stk.push(i);
            } else {
                maxLen = max(maxLen, i - stk.top());
            }
        }
    }
    return maxLen;
}

#endif //DATA_STRUCTURE_ASS2_LONGESTVALIDPARENTHESES_H
