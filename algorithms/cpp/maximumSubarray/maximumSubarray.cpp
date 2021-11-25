// Source : https://leetcode.com/problems/maximum-subarray/
// Author : https://github.com/xinsheng
// Date   : 2021-11-25

/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Add the number to the temprary `sum`, and save the max int to `ret`
 * reset sum when less than 0, because the number less than 0 does not contribute the `ret`
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int n = nums.size();

        int sum = 0;
        for (size_t i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > ret) ret = sum;
			
            if (sum < 0) {
				//reset sum
                sum = 0;
            }
        }

        return ret;
    }
};

/*
	Solution s;
	vector<int> v;
	v = { -2,1,-3,4,-1,2,1,-5,4 };
	EXPECT_EQ(s.maxSubArray(v), 6);
	v = { 5,4,-1,7,8 };
	EXPECT_EQ(s.maxSubArray(v), 23);
	v = { -2, -1 };
	EXPECT_EQ(s.maxSubArray(v), -1);
	v = {-1};
	EXPECT_EQ(s.maxSubArray(v), -1);
	v = { -1,-3,-3 };
	EXPECT_EQ(s.maxSubArray(v), -1);
*/