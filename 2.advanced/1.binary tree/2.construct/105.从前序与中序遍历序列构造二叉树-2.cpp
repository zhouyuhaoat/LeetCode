/*
 *   author:    zhouyuhao
 *   created:   2024-12-19 23:28:58
 *   modified:  2025-03-16 11:25:35
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, int> inPos;

    TreeNode *build(int preR, int inL, int inH, vector<int>& pre, vector<int>& in) { // [inL, inH)
        if (inL >= inH) return nullptr;
        int inR = inPos[pre[preR]];
        TreeNode *left = build(preR + 1, inL, inR, pre, in);
        TreeNode *right = build(preR + (inR - inL) + 1, inR + 1, inH, pre, in);
        // left subtree: [inL, inR); right subtree: [inR + 1, inH)
        return new TreeNode(pre[preR], left, right);
    }

public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); i++) {
            inPos[inorder[i]] = i;
        }
        return build(0, 0, inorder.size(), preorder, inorder);
    }
};
// @lc code=end
