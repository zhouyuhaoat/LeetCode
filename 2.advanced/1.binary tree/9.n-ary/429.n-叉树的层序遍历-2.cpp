/*
 *   author:    zhouyuhao
 *   created:   2025-12-12 22:21:33
 *   modified:  2025-12-14 10:24:11
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        vector<Node *> curr;
        if (root) curr.emplace_back(root);
        while (!curr.empty()) {
            res.emplace_back();
            vector<Node *> next;
            for (Node *node : curr) {
                res.back().emplace_back(node->val);
                next.insert(next.end(), node->children.begin(), node->children.end());
            }
            curr = move(next);
        }
        return res;
    }
};
// @lc code=end
