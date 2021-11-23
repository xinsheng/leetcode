// Source : https://leetcode.com/problems/palindrome-number/
// Author : https://github.com/xinsheng
// Date   : 2021-11-22

/*
 * Given an integer x, return true if x is palindrome integer.
 */

#include <string.h>
#include <iostream>
#include <string>
using namespace std;

/*
 * Idea:
 * Convert it to string, and compare it from first with last.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        bool ret = true;
        char b[1024] = { 0 };
        sprintf(b,"%d", x);
        int len = strlen(b);
        for (int i = 0; i < len / 2; i++) {
            if (b[i] != b[len - i - 1]) {
                ret = false;
                break;
            }
        }
        return ret;
    }
};
