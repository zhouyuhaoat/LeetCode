/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-02-25 12:24:35
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

// @lc code=start
class Solution {
private:
    stack<int> toStack(ListNode *head) {
        stack<int> stk;
        while (head) {
            stk.emplace(head->val);
            head = head->next;
        }
        return stk;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        stack<int> stk1 = toStack(l1), stk2 = toStack(l2);
        int carry = 0;
        while (!stk1.empty() || !stk2.empty() || carry > 0) {
            int sum = (stk1.empty() ? 0 : stk1.top()) + (stk2.empty() ? 0 : stk2.top()) + carry;
            carry = sum / 10;
            if (!stk1.empty()) stk1.pop();
            if (!stk2.empty()) stk2.pop();
            ListNode *curr = new ListNode(sum % 10);
            curr->next = head, head = curr;
        }
        return head;
    }
};
// @lc code=end
