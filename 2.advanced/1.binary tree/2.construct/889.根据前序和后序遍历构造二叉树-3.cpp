/*
 *   author:    zhouyuhao
 *   created:   2025-03-16 20:46:53
 *   modified:  2025-03-17 14:34:35
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

// @lc code=start
class Solution {
public:
    TreeNode *constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postPos;
        for (int i = 0; i < (int)postorder.size(); i++) {
            postPos[postorder[i]] = i;
        }

        function<TreeNode *(int, int, int)> construct = [&](int preR, int postL, int postH) -> TreeNode * { // [postL, postH)
            if (postL >= postH) return nullptr;
            int size = 0; // prioritize left subtree
            if (postL + 1 < postH) size = postPos[preorder[preR + 1]] - postL + 1; // leftR - postL + 1
            TreeNode *left = construct(preR + 1, postL, postL + size);
            TreeNode *right = construct(preR + size + 1, postL + size, postH - 1);
            // left subtree: [postL, postL + size); right subtree: [postL + size, postH - 1)
            return new TreeNode(preorder[preR], left, right);
        };

        return construct(0, 0, postorder.size());
    }
};
// @lc code=end
