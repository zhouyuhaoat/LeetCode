/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 10:56:37
 *   modified:  2025-12-16 11:02:18
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head) return nullptr; // empty list
        if (!head->next) return head; // single node
        ListNode *newHead = reverseList(head->next), *newTail = head->next;
        /*
                nullptr   newTail      newHead
                    ^        |            |
                    |        v            v
            head -> head->next <- ... <- tail
         */
        newTail->next = head, head->next = nullptr; // tail insertion
        return newHead;
    }
};
// @lc code=end
