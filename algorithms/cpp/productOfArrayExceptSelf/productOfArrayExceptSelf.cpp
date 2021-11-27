// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : https://github.com/xinsheng
// Date   : 2021-11-27

/*
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Iterate all the nums, and store left and right product value, then join it to `ans`
 1 2 3 4
   - - -
 1 2 3 4
 -   - -
 1 2 3 4
 - -   -
 1 2 3 4
 - - - 
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) {
            swap(nums[0], nums[1]);
            return nums;
        }
        vector<int> left;
        vector<int> right;
        int productLeft = 1;
        int productRight = 1;
		//store left and right product
        int n1 = n - 1;
        for (int i = 1; i < n1; i++) {
            productLeft *= nums[i - 1];
            left.push_back(productLeft);

            productRight *= nums[n-i];
            right.push_back(productRight);
        }
		//join
        vector<int> ans;
        ans.push_back(nums[1]*right.back());
        for (int i = 0; i < n1 - 1; i++) {
            ans.push_back(left[i] * right[n1 - i - 2]);
        }
        ans.push_back(nums[n-2]*left.back());
        
        return ans;
    }
};

/*
 * Idea:
 * Get the product of right first.
 */

 
class Solution_2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        
        for(int i = n-2; i>=0; i--){
            ans[i] = ans[i+1] * nums[i+1];
        }
        
        int productLeft = 1;
        for(int i = 0; i< n; i++){
            ans[i] = ans[i] * productLeft;
            productLeft *= nums[i];
        }
        return ans;
    }
};
	