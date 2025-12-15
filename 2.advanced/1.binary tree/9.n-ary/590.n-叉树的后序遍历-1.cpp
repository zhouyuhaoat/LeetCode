/*
 *   author:    zhouyuhao
 *   created:   2025-12-12 22:22:20
 *   modified:  2025-12-14 10:36:28
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
private:
    void postorderTraversal(Node *root, vector<int>& res) {
        if (!root) return;
        for (Node *child : root->children) {
            postorderTraversal(child, res);
        }
        res.emplace_back(root->val);
    }

public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }
};
// @lc code=end
