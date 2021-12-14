// Source : https://leetcode.com/problems/range-sum-of-bst/
// Author : https://github.com/xinsheng
// Date   : 2021-12-14

/*
Discuss:
https://leetcode.com/problems/range-sum-of-bst/discuss/1628331/Super-Easy-Solution-in-C%2B%2B
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int sum = 0;
    void helper(TreeNode* root, int low, int high){
        if(root){
           if(root->val >= low && root->val <= high){
              sum += root->val;
           }
           helper(root->left, low, high);
           helper(root->right, low, high);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root, low, high);
        return sum;
    }
};
	