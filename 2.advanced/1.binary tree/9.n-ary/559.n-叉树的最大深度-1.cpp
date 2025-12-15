/*
 *   author:    zhouyuhao
 *   created:   2024-12-18 20:18:37
 *   modified:  2025-03-10 17:21:40
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    int maxDepth(Node *root) {
        int depth = 0;
        queue<Node *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            depth++;
            for (int i = q.size(); i > 0; i--) {
                Node *node = q.front();
                q.pop();
                for (Node *child : node->children) {
                    q.emplace(child);
                }
            }
        }
        return depth;
    }
};
// @lc code=end
