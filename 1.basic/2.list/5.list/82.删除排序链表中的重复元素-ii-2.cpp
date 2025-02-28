/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-27 20:42:46
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head), *pre = &dummy, *cur = head;
        while (cur && cur->next) { // pairs
            int val = cur->val;
            if (cur->next->val == val) { // duplicate
                while (cur && cur->val == val) {
                    pre->next = cur->next;
                    ListNode* tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }
            } else {
                pre = pre->next, cur = cur->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
