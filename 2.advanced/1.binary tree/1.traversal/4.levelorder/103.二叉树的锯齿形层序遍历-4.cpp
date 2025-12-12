/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:13:25
 *   modified:  2025-03-09 13:47:30
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
            deque<int> level; // double-ended queue
            void (deque<int>::*push_fn)(const int&) = zigzag ? static_cast<void (deque<int>::*)(const int&)>(&deque<int>::push_front)
                                                             : static_cast<void (deque<int>::*)(const int&)>(&deque<int>::push_back);
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                (level.*push_fn)(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res.emplace_back(vector<int>{level.begin(), level.end()});
            zigzag = !zigzag;
        }
        return res;
    }
};
// @lc code=end
