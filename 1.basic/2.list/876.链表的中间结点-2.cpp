/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-31 17:19:58
 * 	 modified: 	2024-11-02 19:07:49
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        int n = getSize(head) / 2;
        ListNode* cur = head;
        while (n--) {
            cur = cur->next;
        }
        return cur;
    }
};
// @lc code=end
