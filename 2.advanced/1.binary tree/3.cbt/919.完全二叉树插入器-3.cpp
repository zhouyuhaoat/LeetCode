/*
 *   author:    zhouyuhao
 *   created:   2025-03-19 20:07:22
 *   modified:  2025-03-19 20:11:23
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 */

// @lc code=start
class CBTInserter {
private:
    int size = 0;
    TreeNode *root;

public:
    CBTInserter(TreeNode *root) {
        this->root = root;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            size++;
            TreeNode *node = q.front();
            q.pop();
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
    }

    int insert(int val) {
        size++;
        TreeNode *par = root;
        int hiBit = 31 - __builtin_clz(size), bits = 1 << (hiBit - 1);
        while (!(bits & 1)) { // !(bits & 1) for parent
            if (size & bits) {
                par = par->right;
            } else {
                par = par->left;
            }
            bits >>= 1;
        }
        if (size & 1) {
            par->right = new TreeNode(val);
        } else {
            par->left = new TreeNode(val);
        }
        return par->val;
    }

    TreeNode *get_root() {
        return root;
    }
};
// @lc code=end
