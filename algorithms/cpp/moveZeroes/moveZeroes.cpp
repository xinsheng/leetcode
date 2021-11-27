// Source : https://leetcode.com/problems/move-zeroes/
// Author : https://github.com/xinsheng
// Date   : 2021-11-27

/*
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Remove all 0 in vector, and append all in tail.
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        int i = 0;
        while (i<nums.size()) {
            if (nums[i] == 0) {
                zeroCount++;
                nums.erase(nums.begin()+i);
            }
            else {
                i++;
            }
        }
        for (int i = 0; i < zeroCount; i++) {
            nums.push_back(0);
        }
    }
};

/*
	Solution s;
	vector<int> v;
	vector<int> r;
	v = { -2, 100,0,1 }; r = {-2,100,1,0};
	s.moveZeroes(v);
	EXPECT_EQ(v, r);

	v = { 0,0,1,0 }; r = { 1,0,0,0 };
	s.moveZeroes(v);
	EXPECT_EQ(v, r);
*/
	