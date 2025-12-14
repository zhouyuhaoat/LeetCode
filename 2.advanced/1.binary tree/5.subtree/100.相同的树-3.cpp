/*
 *   author:    zhouyuhao
 *   created:   2025-03-20 14:46:46
 *   modified:  2025-03-31 20:55:43
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> que;
        que.emplace(p), que.emplace(q);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            // nullptr acts as placeholder
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            que.emplace(p->left), que.emplace(q->left);
            que.emplace(p->right), que.emplace(q->right);
        }
        return true;
    }
};
// @lc code=end
