/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 17:48:50
 * 	 modified: 	2024-11-02 17:50:04
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
        ListNode dummy{0, head};
        ListNode *lo = &dummy, *hi = &dummy; // all from dummy
        while (n--) {
            hi = hi->next;
        }
        while (hi->next) { // next for pre
            lo = lo->next;
            hi = hi->next;
        }
        lo->next = lo->next->next;
        return dummy.next;
    }
};
// @lc code=end
