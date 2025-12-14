/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 22:15:11
 *   modified:  2025-12-13 22:18:42
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
private:
    Node *levelorder(Node *root) {
        queue<Node *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                Node *node = q.front();
                q.pop();
                if (i > 1) node->next = q.front(); // connect
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return root;
    }

public:
    Node *connect(Node *root) {
        return levelorder(root);
    }
};
// @lc code=end
