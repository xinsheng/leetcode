// Source : https://leetcode.com/problems/rotate-array/
// Author : https://github.com/xinsheng
// Date   : 2021-11-26

/*
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Becareful when k > nums.size(), it's a trap :(
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
		//becareful if n > n, just get the remainder, because if k == n, the result is same nums.
        if (k > n) {
            k = k % n;
        }
        vector<int> res;
        for (size_t i = (n - k); i < n; i++) {
            res.push_back(nums[i]);
        }
        for (size_t i = 0; i < (n-k); i++) {
            res.push_back(nums[i]);
        }
        nums = res;
    }
};

/*
TEST(validParentheses, Test) {
	Solution s;
	vector<int> v;
	vector<int> r;//result

	v = { 1,2,3,4,5,6,7 };
	s.rotate(v,3);
	r = { 5,6,7,1,2,3,4 };
	EXPECT_EQ(v, r);

	v = { 1,2 }; r = { 1,2 };
	s.rotate(v, 0);
	EXPECT_EQ(v, r);

	v = { -1 }; r = { -1 };
	s.rotate(v, 2);
	EXPECT_EQ(v, r);

	v = { 1,2 }; r = { 2,1 };
	s.rotate(v, 3);
	EXPECT_EQ(v, r);

	v = { 1,2 }; r = { 1,2 };
	s.rotate(v, 4);
	EXPECT_EQ(v, r);

	v = { -1,-100,3,99 };
	s.rotate(v, 2);
	r = { 3,99,-1,-100 };
	EXPECT_EQ(v, r);
}
*/
	