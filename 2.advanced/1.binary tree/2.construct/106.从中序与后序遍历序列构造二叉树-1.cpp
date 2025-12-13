/*
 *   author:    zhouyuhao
 *   created:   2024-12-19 17:59:18
 *   modified:  2025-03-16 11:25:57
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *build(int postR, int inL, int inH, vector<int>& in, vector<int>& post) { // [inL, inH]
        if (inL > inH) return nullptr;
        // find root in inorder, to split left and right subtree
        int inR = distance(in.begin(), ranges::find(in, post[postR]));
        TreeNode *root = new TreeNode(post[postR]);
        root->left = build(postR - (inH - inR) - 1, inL, inR - 1, in, post); // right subtree size: inH - inR
        root->right = build(postR - 1, inR + 1, inH, in, post);
        // left subtree: [inL, inR - 1]; right subtree: [inR + 1, inH]
        return root;
    }

public:
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end
