/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:36:28
 *   modified:  2025-03-19 10:10:42
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
 */

// @lc code=start
class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        int size = 0, last = 0; // id of last node
        queue<pair<TreeNode *, unsigned long long>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            auto [node, id] = q.front();
            q.pop();
            size++, last = id;
            if (!node) continue;
            q.emplace(node->left, id * 2);
            q.emplace(node->right, id * 2 + 1);
        }
        return size == last;
    }
};
// @lc code=end
