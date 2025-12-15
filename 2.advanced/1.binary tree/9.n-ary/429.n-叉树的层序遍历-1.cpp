/*
 *   author:    zhouyuhao
 *   created:   2025-12-12 22:21:33
 *   modified:  2025-12-14 10:20:24
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        queue<Node *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            res.emplace_back();
            for (int i = q.size(); i > 0; i--) {
                Node *node = q.front();
                q.pop();
                res.back().emplace_back(node->val);
                for (Node *child : node->children) {
                    q.emplace(child);
                }
            }
        }
        return res;
    }
};
// @lc code=end
