/*
 *   author:    zhouyuhao
 *   created:   2024-12-21 19:26:12
 *   modified:  2025-03-17 14:32:28
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
private:
    TreeNode *construct(int postR, int preL, int preH, vector<int>& pre, vector<int>& post) { // [preL, preH)
        if (preL >= preH) return nullptr;
        if (preL + 1 == preH) return new TreeNode(post[postR]);
        // prioritize right subtree: find the root of right subtree in preorder, to split left and right subtree
        int rightR = distance(pre.begin(), ranges::find(pre, post[postR - 1]));
        TreeNode *left = construct(postR - (preH - rightR) - 1, preL + 1, rightR, pre, post); // right subtree size: preH - rightR
        TreeNode *right = construct(postR - 1, rightR, preH, pre, post);
        // left subtree: [preL + 1, rightR); right subtree: [rightR, preH)
        return new TreeNode(post[postR], left, right);
    }

public:
    TreeNode *constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(postorder.size() - 1, 0, preorder.size(), preorder, postorder);
    }
};
// @lc code=end
