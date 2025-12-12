/*
 *   author:    zhouyuhao
 *   created:   2024-12-18 19:52:49
 *   modified:  2025-03-07 22:32:35
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) { // visitAlongVine -> leftmost vine
                stk.emplace(root);
                res.emplace_back(root->val);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
