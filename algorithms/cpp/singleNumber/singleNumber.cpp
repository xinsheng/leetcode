// Source : https://leetcode.com/problems/single-number/
// Author : https://github.com/xinsheng
// Date   : 2021-12-08

/*
Discuss:
https://leetcode.com/problems/single-number/discuss/1617742/C%2B%2B-easy-solution
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        sort(nums.begin(), nums.end());
        if(nums[0] != nums[1]) return nums[0];

        int n = nums.size();
        for (int i = 1; i <n-1; i++) {
            if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[n-1];
    }
};


class Solution_2 {
public:
    int singleNumber(vector<int>& nums) {
     
        int res = nums[0];
        for (int i=1; i<nums.size();i++)
        {
            //Apply XOR operation
            res ^= nums[i];
        }
        return res;
    }
};