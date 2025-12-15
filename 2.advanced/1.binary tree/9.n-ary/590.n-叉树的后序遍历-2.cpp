/*
 *   author:    zhouyuhao
 *   created:   2025-12-12 22:22:20
 *   modified:  2025-12-14 10:38:30
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        stack<Node *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            for (Node *child : root->children) {
                stk.emplace(child);
            }
        }
        ranges::reverse(res);
        return res;
    }
};
// @lc code=end
