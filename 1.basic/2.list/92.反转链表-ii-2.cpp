/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 00:58:47
 * 	 modified: 	2024-11-03 01:48:43
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    void reverseLinkedList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head), *pre = &dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *le = pre->next, *ri = pre;
        for (int i = left; i < right + 1; i++) {
            ri = ri->next;
        }
        ListNode* succ = ri->next;
        // pre -> le -> ... -> ri -> succ
        pre->next = ri->next = nullptr; // cut
        reverseLinkedList(le);
        pre->next = ri;
        le->next = succ;
        return dummy.next;
    }
};
// @lc code=end
