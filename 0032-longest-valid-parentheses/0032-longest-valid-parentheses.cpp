#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1); // Initialize the stack with -1

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i); // Push the index of '(' to the stack
            } else {
                stk.pop(); // Pop the '(' index
                if (stk.empty()) {
                    stk.push(i); // If the stack is empty, push the current index
                } else {
                    ans = max(ans, i - stk.top()); // Update the result
                }
            }
        }

        return ans;
    }
};


