/*
 *   author:    zhouyuhao
 *   created:   2025-12-13 17:58:26
 *   modified:  2025-12-13 18:21:23
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
class Solution {
public:
    Node *connect(Node *root) {
        Node *leftmost = root;
        while (leftmost) {
            Node *curr = leftmost; // current level
            Node dummy, *next = &dummy; // next level
            while (curr) {
                if (curr->left) {
                    next = next->next = curr->left;
                }
                if (curr->right) {
                    next = next->next = curr->right;
                }
                curr = curr->next; // connected before
            }
            leftmost = dummy.next; // leftmost node of each level
        }
        return root;
    }
};
// @lc code=end
