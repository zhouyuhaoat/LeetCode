/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 10:35:10
 *   modified:  2025-12-14 10:08:58
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 */

// @lc code=start
class Solution {
private:
    TreeNode dummy, *tail = &dummy;

    void inorder(TreeNode *root) {
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            tail->left = nullptr; // (delayed) cut
            tail = tail->right = root;
            root = root->right;
        }
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        inorder(root);
        tail->left = nullptr; // final cut
        return dummy.right;
    }
};
// @lc code=end
