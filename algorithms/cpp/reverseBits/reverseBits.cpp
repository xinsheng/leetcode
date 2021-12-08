// Source : https://leetcode.com/problems/reverse-bits/
// Author : https://github.com/xinsheng
// Date   : 2021-12-08

/*
Discuss:
https://leetcode.com/problems/reverse-bits/discuss/1617695/Super-Clear-C%2B%2B-Solution
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 32;
        while (i--) {
            int t = n & 1;
            n = n >> 1;
            ans = (ans << 1) | t;
        }
        return ans;
    }
};
	