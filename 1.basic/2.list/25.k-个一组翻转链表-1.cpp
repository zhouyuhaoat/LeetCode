/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 00:05:12
 * 	 modified: 	2024-11-03 00:40:42
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
    int getSize(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *ps = &dummy, *pre = nullptr, *cur = head;
        for (int n = getSize(head); n >= k; n -= k) {
            for (int i = 0; i < k; i++) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            // ps -> next <- ... <- pre + cur
            ListNode* next = ps->next;
            ps->next->next = cur;
            ps->next = pre;
            ps = next;
        }
        return dummy.next;
    }
};
// @lc code=end
