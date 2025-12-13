/*
 *   author:    zhouyuhao
 *   created:   2024-12-19 17:38:13
 *   modified:  2025-03-16 11:26:24
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *build(int preR, int inL, int inH, vector<int>& pre, vector<int>& in) { // [inL, inH]
        if (inL > inH) return nullptr;
        // find root in inorder, to split left and right subtree
        int inR = distance(in.begin(), ranges::find(in, pre[preR]));
        TreeNode *root = new TreeNode(pre[preR]);
        root->left = build(preR + 1, inL, inR - 1, pre, in);
        root->right = build(preR + (inR - inL) + 1, inR + 1, inH, pre, in); // left subtree size: inR - inL
        // left subtree: [inL, inR - 1]; right subtree: [inR + 1, inH]
        return root;
    }

public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, 0, inorder.size() - 1, preorder, inorder);
    }
};
// @lc code=end
