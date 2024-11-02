/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 15:20:27
 * 	 modified: 	2024-11-02 15:24:22
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
        ListNode *dummy = new ListNode(0, head), *cur = dummy;
        stack<ListNode*> st;
        while (cur) {
            st.emplace(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; i++) { // pop out the node
            st.pop();
        }
        ListNode* pre = st.top();
        pre->next = pre->next->next;
        return dummy->next;
    }
};
// @lc code=end
