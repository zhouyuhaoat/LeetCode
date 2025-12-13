/*
 *   author:    zhouyuhao
 *   created:   2024-12-19 17:59:18
 *   modified:  2025-03-16 11:27:16
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, int> inPos;

    TreeNode *build(int postR, int inL, int inH, vector<int>& in, vector<int>& post) { // [inL, inH)
        if (inL >= inH) return nullptr;
        int inR = inPos[post[postR]];
        TreeNode *left = build(postR - (inH - inR - 1) - 1, inL, inR, in, post); // right subtree size: inH - inR - 1
        TreeNode *right = build(postR - 1, inR + 1, inH, in, post);
        // left subtree: [inL, inR); right subtree: [inR + 1, inH)
        return new TreeNode(post[postR], left, right);
    }

public:
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < (int)inorder.size(); i++) {
            inPos[inorder[i]] = i;
        }
        return build(postorder.size() - 1, 0, inorder.size(), inorder, postorder);
    }
};
// @lc code=end
