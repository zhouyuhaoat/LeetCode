/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 22:47:49
 *   modified:  2025-03-07 22:48:47
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
        while (true) {
            if (root) {
                stk.emplace(root);
                res.emplace_back(root->val);
                root = root->left;
            } else if (!stk.empty()) {
                root = stk.top();
                stk.pop();
                root = root->right;
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
