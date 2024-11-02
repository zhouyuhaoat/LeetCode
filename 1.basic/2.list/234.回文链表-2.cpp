/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 01:25:50
 * 	 modified: 	2024-11-03 01:32:23
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* mi = middleNode(head);
        ListNode* newHead = reverseList(mi);
        while (newHead) {
            if (head->val != newHead->val) {
                return false;
            }
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};
// @lc code=end
