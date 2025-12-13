/*
 *   author:    zhouyuhao
 *   created:   2024-12-21 14:19:54
 *   modified:  2025-03-17 14:32:34
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode *construct(int preR, int postL, int postH, vector<int>& pre, vector<int>& post) { // [postL, postH]
        if (postL > postH) return nullptr;
        TreeNode *root = new TreeNode(pre[preR]);
        if (postL == postH) return root;
        // prioritize left subtree: find the root of left subtree in postorder, to split left and right subtree
        int leftR = distance(post.begin(), ranges::find(post, pre[preR + 1]));
        root->left = construct(preR + 1, postL, leftR, pre, post);
        root->right = construct(preR + (leftR - postL + 1) + 1, leftR + 1, postH - 1, pre, post); // left subtree size: leftR - postL + 1
        // left subtree: [postL, leftR]; right subtree: [leftR + 1, postH - 1]
        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(0, 0, postorder.size() - 1, preorder, postorder);
    }
};
// @lc code=end
