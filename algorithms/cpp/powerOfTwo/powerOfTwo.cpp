// Source : https://leetcode.com/problems/power-of-two/
// Author : https://github.com/xinsheng
// Date   : 2021-12-07

/*
Discuss:
https://leetcode.com/problems/power-of-two/discuss/1615799/Super-clean-and-easy-understand-C%2B%2B-solution-or-100-fast
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        while(n > 2){
            if(n%2 != 0) return false;
            n = n/2;
        }
        return (n == 2);
    }
};

class Solution_2 {
public:
    bool isPowerOfTwo(int n) {
        if (n==0) return false;
        double m = log2(n);
        if(floor(m) == m){
            return true;
        }
        return false;
    }
};

	