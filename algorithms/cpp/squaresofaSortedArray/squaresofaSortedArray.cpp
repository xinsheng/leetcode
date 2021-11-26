// Source : https://leetcode.com/problems/squares-of-a-sorted-array/
// Author : https://github.com/xinsheng
// Date   : 2021-11-26

/*
 * Given an integer array nums sorted in non-decreasing order, 
 * return an array of the squares of each number sorted in non-decreasing order.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * I don't know if the sort() function is leagle :D
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i ++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

	