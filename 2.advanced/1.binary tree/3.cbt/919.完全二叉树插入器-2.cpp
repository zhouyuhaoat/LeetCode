/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:34:41
 *   modified:  2025-03-19 10:07:18
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
    int size = 0; // id: 1-based index
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
        int hiBit = 31 - __builtin_clz(size); // the highest bit
        for (int i = hiBit - 1; i > 0; i--) { // hi - 1 since root, also the length of path; i > 0 for parent
            if (size & (1 << i)) {
                par = par->right;
            } else {
                par = par->left;
            }
        }
        if (size & 1) { // parent -> child
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
