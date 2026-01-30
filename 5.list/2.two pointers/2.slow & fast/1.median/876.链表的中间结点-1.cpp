/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-27 18:40:31
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
class Solution {
private:
    vector<ListNode *> toVector(ListNode *head) {
        vector<ListNode *> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        return vec;
    }

public:
    ListNode *middleNode(ListNode *head) {
        vector<ListNode *> vec = toVector(head);
        return vec[vec.size() / 2]; // (right) median
    }
};
// @lc code=end
