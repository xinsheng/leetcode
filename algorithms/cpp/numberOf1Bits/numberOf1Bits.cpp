// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : https://github.com/xinsheng
// Date   : 2021-12-07

/*
Discuss:
https://leetcode.com/problems/number-of-1-bits/discuss/1615840/C%2B%2B-2-simple-approaches-or-100-fast
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        while(n>0){
            n=((n)&(n-1));
            i++;
        }
        return i;
    }
};


class Solution_2 {
public:
    int hammingWeight(uint32_t n) {
        int i =0;
        while(n!=0){
            if(n%2 == 1){
                i++;
            }
            n = n>>1;
        }
        return i;
    }
};