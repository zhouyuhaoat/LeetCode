/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 12:16:48
 *   modified:  2025-03-15 23:24:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            if (root) {
                stk.emplace(root), stk.emplace(nullptr); // marker
                if (root->right) stk.emplace(root->right);
                if (root->left) stk.emplace(root->left);
            } else {
                res.emplace_back(stk.top()->val);
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
