/*
 *   author:    zhouyuhao
 *   created:   2024-12-19 18:04:29
 *   modified:  2025-07-05 16:42:20
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode *construct(int lo, int hi, vector<int>& nums) { // [lo, hi)
        if (lo >= hi) return nullptr;
        auto root = max_element(nums.begin() + lo, nums.begin() + hi);
        int mi = distance(nums.begin(), root);
        TreeNode *left = construct(lo, mi, nums), *right = construct(mi + 1, hi, nums);
        return new TreeNode(*root, left, right);
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int>& nums) {
        return construct(0, nums.size(), nums);
    }
};
// @lc code=end
