/*
 *   author:    zhouyuhao
 *   created:   2025-12-12 22:22:12
 *   modified:  2025-12-14 10:32:13
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    void preorderTraversal(Node *root, vector<int>& res) {
        if (!root) return;
        res.emplace_back(root->val);
        for (Node *child : root->children) {
            preorderTraversal(child, res);
        }
    }

public:
    vector<int> preorder(Node *root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
};
// @lc code=end
