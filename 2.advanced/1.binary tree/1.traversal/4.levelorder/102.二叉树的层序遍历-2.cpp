/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 15:14:21
 *   modified:  2025-03-15 23:34:04
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        vector<TreeNode *> curr;
        if (root) curr.emplace_back(root);
        while (!curr.empty()) {
            res.emplace_back();
            vector<TreeNode *> next;
            for (TreeNode *node : curr) {
                res.back().emplace_back(node->val);
                if (node->left) next.emplace_back(node->left);
                if (node->right) next.emplace_back(node->right);
            }
            curr = move(next);
        }
        return res;
    }
};
// @lc code=end
