/*
 *   author:    zhouyuhao
 *   created:   2024-12-21 14:17:53
 *   modified:  2025-03-18 21:59:55
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
class Solution {
private:
    vector<TreeNode *> tree;
    vector<int> left, right; // bound: first greater number on the left and right

    void init(vector<int>& nums) {
        int n = nums.size();
        left.resize(n, -1), right.resize(n, -1); // sentinel
        for (int i = 0; i < n; i++) {
            tree.emplace_back(new TreeNode(nums[i]));
        }
    }

    void getLeftRight(vector<int>& nums) {
        stack<int> stk; // monotonic (descending) stack
        for (int i = 0; i < (int)nums.size(); i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) left[i] = stk.top();
            stk.emplace(i);
        }
    }

    TreeNode *construct(vector<int>& nums) {
        // the closer greater number is the parent
        TreeNode *root = nullptr;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (left[i] == -1 && right[i] == -1) { // the root
                root = tree[i];
            } else if (left[i] == -1 || (right[i] != -1 && nums[right[i]] < nums[left[i]])) {
                tree[right[i]]->left = tree[i]; // left child of right closer greater
            } else {
                tree[left[i]]->right = tree[i]; // right child of left closer greater
            }
        }
        return root;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int>& nums) {
        init(nums);
        getLeftRight(nums);
        return construct(nums);
    }
};
// @lc code=end
