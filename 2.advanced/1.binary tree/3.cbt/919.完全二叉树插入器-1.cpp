/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:30:49
 *   modified:  2025-03-19 09:42:40
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
    TreeNode *root;
    queue<TreeNode *> candidate; // non-full nodes at the last one or two levels

public:
    CBTInserter(TreeNode *root) {
        this->root = root;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
            if (!(node->left && node->right)) candidate.emplace(node);
        }
    }

    int insert(int val) {
        TreeNode *newNode = new TreeNode(val);
        TreeNode *par = candidate.front(); // the first non-full node, also the parent of the new node
        if (!par->left) {
            par->left = newNode;
        } else {
            par->right = newNode;
            candidate.pop();
        }
        candidate.emplace(newNode);
        return par->val;
    }

    TreeNode *get_root() {
        return root;
    }
};
// @lc code=end
