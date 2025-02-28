/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:24
 *   modified:  2025-02-25 12:50:02
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *ptr = &dummy, *cur = head;
        while (cur) {
            ListNode* tail = ptr;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy.next;
            }
            ListNode* pre = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode* tmp = cur->next;
                cur->next = pre;
                pre = cur, cur = tmp;
            }
            // ptr -> next <- ... <- pre, cur
            ListNode* next = ptr->next; // backup
            ptr->next = pre;
            next->next = cur;
            // ptr -> pre -> ... > next -> cur
            ptr = next;
        }
        return dummy.next;
    }
};
// @lc code=end
