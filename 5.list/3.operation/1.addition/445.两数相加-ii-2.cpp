/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:26
 *   modified:  2025-02-25 12:24:52
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
    string toString(ListNode *head) {
        string s;
        while (head) {
            s.push_back(head->val + '0');
            head = head->next;
        }
        return s;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        string s1 = toString(l1), s2 = toString(l2);
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0; // reverse addition
        while (i >= 0 || j >= 0 || carry) {
            int sum = (i >= 0 ? s1[i--] - '0' : 0) + (j >= 0 ? s2[j--] - '0' : 0) + carry;
            ListNode *curr = new ListNode(sum % 10);
            curr->next = head, head = curr; // head insertion
            carry = sum / 10;
        }
        return head;
    }
};
// @lc code=end
