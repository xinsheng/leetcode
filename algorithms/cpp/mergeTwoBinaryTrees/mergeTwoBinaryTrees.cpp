// Source : https://leetcode.com/problems/merge-two-binary-trees/
// Author : https://github.com/xinsheng
// Date   : 2021-12-02

/*
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Idea:
Thanks for:
https://leetcode.com/problems/merge-two-binary-trees/discuss/104308/JavaC%2B%2B-Clean-Code-Unique-Node-or-Shared-Node-5-liner
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;

        TreeNode* node = new TreeNode((root1 ? root1->val : 0) + (root2 ? root2->val : 0));
        node->left = mergeTrees((root1 ? root1->left : nullptr), (root2 ? root2->left : nullptr));
        node->right = mergeTrees((root1 ? root1->right : nullptr), (root2 ? root2->right : nullptr));
        return node;
    }
};

class Solution_2 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) return t1 ? t1 : t2;

        TreeNode* node = new TreeNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }
};