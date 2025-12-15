/*
 *   author:    zhouyuhao
 *   created:   2025-12-12 22:22:12
 *   modified:  2025-12-14 10:32:44
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> res;
        stack<Node *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            for (auto it = root->children.rbegin(); it != root->children.rend(); it++) {
                stk.emplace(*it);
            }
        }
        return res;
    }
};
// @lc code=end
