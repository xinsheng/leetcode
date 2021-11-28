// Source : https://leetcode.com/problems/reverse-string/
// Author : https://github.com/xinsheng
// Date   : 2021-11-28

/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Idea:
Reverse string from start to end.
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j=s.size()-1;
        while(i < j){
            swap(s[i++], s[j--]);
        }
    }
};
