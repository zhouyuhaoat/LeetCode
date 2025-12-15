/*
 *   author:    zhouyuhao
 *   created:   2025-03-05 10:53:51
 *   modified:  2025-03-09 15:53:42
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
    bool valid(vector<int>& vec, int level) {
        for (int i = 0; i < (int)vec.size(); i++) {
            if (vec[i] % 2 == level % 2) return false;
            if (i > 0 && vec[i] == vec[i - 1]) return false;
        }
        if (level % 2) { // strictly ordered
            return ranges::is_sorted(vec, greater<int>());
        }
        return ranges::is_sorted(vec);
    }

public:
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.emplace(root);
        int level = 0;
        while (!q.empty()) {
            vector<int> layer;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                layer.emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            if (!valid(layer, level)) return false;
            level++;
        }
        return true;
    }
};
// @lc code=end
