/*
 *   author:    zhouyuhao
 *   created:   2025-03-15 23:30:38
 *   modified:  2025-03-16 09:49:37
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
class Solution {
private:
    void reverse(TreeNode* head) { // as reverse of singly-linked list
        TreeNode *pre = nullptr, *cur = head;
        while (cur) {
            TreeNode* next = cur->right;
            cur->right = pre;
            pre = cur, cur = next;
        }
    }
    void addReversePath(TreeNode* head, TreeNode* tail, vector<int>& res) {
        reverse(head);
        TreeNode* node = tail;
        while (node) {
            res.emplace_back(node->val);
            node = node->right;
        }
        reverse(tail); // restore the path
        // root->left always points to 'head'
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dummy(0, root, nullptr);
        root = &dummy;
        while (root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    addReversePath(root->left, pre, res);
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end
