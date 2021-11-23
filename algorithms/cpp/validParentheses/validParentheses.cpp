// Source : https://leetcode.com/problems/valid-parentheses
// Author : https://github.com/xinsheng
// Date   : 2021-11-22

/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
 * Idea:
 * Prepare a stack for store char, pop out nearest compared char.
 * I'm using ASCII to check compared.
 * () 40  41
 * [] 91  93
 * {} 123 125
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (size_t i = 0; i < s.length(); i++) {
            char c = s[i];
            if (stack.size() > 0) {
                int k = c - stack.top();
                if ((k == 1) || (k == 2)) {
                    stack.pop();
                }
                else {
                    stack.push(c);
                }
            }
            else {
                stack.push(c);
            }
        }
        return (stack.size() == 0);
    }
};

/*
TEST(validParentheses, Test) {
    Solution s;
    EXPECT_EQ(s.isValid("[]"), true);
    EXPECT_EQ(s.isValid("()[]{}"), true);
    EXPECT_EQ(s.isValid("([)]"), false);
    EXPECT_EQ(s.isValid("("), false);
    EXPECT_EQ(s.isValid(""), true);
}
*/