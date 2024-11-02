/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 23:14:55
 * 	 modified: 	2024-11-02 23:58:43
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode *pre = tail->next, *cur = head;
        while (pre != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head), *pre = dummy;
        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    return dummy->next;
                }
            }
            ListNode* next = tail->next;
            tie(head, tail) = reverseList(head, tail);
            pre->next = head;
            tail->next = next;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};
// @lc code=end
