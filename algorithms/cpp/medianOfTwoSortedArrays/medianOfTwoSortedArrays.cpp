// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : https://github.com/xinsheng
// Date   : 2021-11-23

/*
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Pick the number one by one from the two arrays to a new `totalNums` array.
 * each time pick the min number, then the new array is ordered.
 * then get the middle number.
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ret = -1;

        int c1 = nums1.size();
        int c2 = nums2.size();
        int n = c1 + c2;
        //special treatment
        if (n == 0) {
            return 0;
        } else if(n <=2) {
            ret = 0;
            for (int i = 0; i < c1; i++) {
                ret += nums1[i];
            }
            for (int i = 0; i < c2; i++) {
                ret += nums2[i];
            }
            return ret / n;
        }

        //determine the middle iterator
        size_t mid = (c1 + c2) / 2;

        size_t i1 = 0;
        size_t i2 = 0;
        int lastInt = 0;
        vector<int> totalNums;
        //place half of vector to totalNums
        for (size_t i = 0; i < n; i++) {
            if (i1 >= c1) {
                lastInt = nums2[i2++];//only add 2
            } else if (i2 >= c2) {
                lastInt = nums1[i1++];//only add 1
            } else if (nums1[i1] < nums2[i2]) {
                lastInt = nums1[i1++];
            }
            else {
                lastInt = nums2[i2++];
            }

            totalNums.push_back(lastInt);
            if (i == (mid)) {
                break;
            }
        }
        //get the middle value;
        if (n % 2) {
            ret = totalNums[mid];
        }
        else {
            ret = double(totalNums[mid - 1] + totalNums[mid]) / 2;
        }
        return ret;
    }
};

/*
TEST(validParentheses, Test) {
	Solution s;
	vector<int> v1 = { 0, 0, 0, 0, 0 };
	vector<int> v2 = { -1, 0, 0, 0, 0, 0, 1 };
	EXPECT_EQ(s.findMedianSortedArrays(v1, v2), 0.0);

	v1 = {1,3 };
	v2 = { 2 };
	EXPECT_EQ(s.findMedianSortedArrays(v1,v2), 2.0);

	v1 = { 1,2 };
	v2 = { 3, 4};
	EXPECT_EQ(s.findMedianSortedArrays(v1, v2), 2.5);
}
*/