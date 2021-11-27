// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author : https://github.com/xinsheng
// Date   : 2021-11-27

/*
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
 * find two numbers such that they add up to a specific target number. 
 * Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Add two number from both side of vector, and move cursor depends on the two numbers sum.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size()-1;
        int i = 0;
        while (i < n) {
            if ((numbers[i] + numbers[n]) > target) {
                n--;
            }
            else if ((numbers[i] + numbers[n]) < target) {
                i++;
            }
            else {
                break;
            }
        }
        vector<int> ans = {i+1,n+1};
        return ans;
    }
};
	