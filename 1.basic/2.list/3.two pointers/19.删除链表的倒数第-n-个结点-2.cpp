/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-02-27 20:41:00
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head), *cur = dummy;
        stack<ListNode*> stk;
        while (cur) {
            stk.emplace(cur);
            cur = cur->next;
        }
        while (n--) { // from end
            stk.pop();
        }
        ListNode* pre = stk.top();
        ListNode* tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        return dummy->next;
    }
};
// @lc code=end
