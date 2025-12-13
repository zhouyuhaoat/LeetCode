/*
 *   author:    zhouyuhao
 *   created:   2025-03-16 20:46:53
 *   modified:  2025-03-17 14:24:57
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
        unordered_map<int, int> prePos;
        for (int i = 0; i < (int)preorder.size(); i++) {
            prePos[preorder[i]] = i;
        }

        auto construct = [&](this auto&& construct, int postR, int preL, int preH) -> TreeNode * { // [preL, preH)
            if (preL >= preH) return nullptr;
            int size = 0; // prioritize right subtree
            if (preL + 1 < preH) size = preH - prePos[postorder[postR - 1]]; // preH - rightR
            auto left = construct(postR - size - 1, preL + 1, preH - size);
            auto right = construct(postR - 1, preH - size, preH);
            // left subtree: [preL + 1, preH - size); right subtree: [preH - size, preH)
            return new TreeNode(postorder[postR], left, right);
        };

        return construct(postorder.size() - 1, 0, preorder.size());
    }
};
// @lc code=end
