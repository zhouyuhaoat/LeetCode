/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-27 21:00:41
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
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
public:
    ListNode* middle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        return pre;
    }
    bool compare(ListNode* head1, ListNode* head2) {
        while (head1 && head2) {
            if (head1->val != head2->val) return false;
            head1 = head1->next, head2 = head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mi = middle(head);
        ListNode* newHead = reverse(mi);
        ListNode *p1 = head, *p2 = newHead;
        bool flag = compare(p1, p2);
        reverse(newHead); // revert
        return flag;
    }
};
// @lc code=end
