/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 15:12:58
 * 	 modified: 	2024-11-02 15:23:53
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
    int getSize(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head), *cur = dummy;
        int len = getSize(head);
        for (int i = 0; i < len - n; i++) { // pre: before the node
            cur = cur->next;
        }
        cur->next = cur->next->next; // delete by bypass or shortcut
        return dummy->next;
    }
};
// @lc code=end
