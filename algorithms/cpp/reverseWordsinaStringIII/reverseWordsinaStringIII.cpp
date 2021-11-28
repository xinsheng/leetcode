// Source : https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author : https://github.com/xinsheng
// Date   : 2021-11-28

/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Idea:
Iterate words one by one, and join it with the reversed word on by one.
 */

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        string tmp;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == ' ') {
                ans += " " + tmp;
                tmp = "";
            }
            else {
                tmp = tmp.insert( 0,1,c);
            }
        }
        if (ans.length() == 0) {
            ans = tmp;
        }
        else {
            ans += " " + tmp;
            ans = ans.substr(1);
        }
        return ans;
    }
};
