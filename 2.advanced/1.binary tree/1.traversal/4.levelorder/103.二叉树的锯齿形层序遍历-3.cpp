/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:05:19
 *   modified:  2025-03-09 13:46:59
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        bool zigzag = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size); // reserve for reverse
            int step = zigzag ? -1 : 1;
            for (int i = 0, idx = zigzag ? size - 1 : 0; i < size; i++, idx += step) {
                TreeNode *node = q.front();
                q.pop();
                level[idx] = node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res.emplace_back(level);
            zigzag = !zigzag;
        }
        return res;
    }
};
// @lc code=end
