// Source : https://leetcode.com/problems/fibonacci-number/
// Author : https://github.com/xinsheng
// Date   : 2021-12-06

/*
Discuss:
https://leetcode.com/problems/fibonacci-number/discuss/1613989/C%2B%2B-or-100-fast-or-Clear-approach
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int prev1 = 0;
        int prev2 = 1;
        int ans = 1;
        
        for(int i = 1; i<n; i++){
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};