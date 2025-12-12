/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 09:27:28
 *   modified:  2025-03-05 09:36:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> res;
        while (root || !stk.empty()) {
            while (root) { // goAlongVine -> leftmost vine
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
