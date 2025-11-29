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
        string str;
        while (head) {
            str.push_back(head->val + '0');
            head = head->next;
        }
        return str;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        string str1 = toString(l1), str2 = toString(l2);
        int i = str1.size() - 1, j = str2.size() - 1, carry = 0; // reverse addition
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = (i >= 0 ? str1[i--] - '0' : 0) + (j >= 0 ? str2[j--] - '0' : 0) + carry;
            carry = sum / 10;
            ListNode *curr = new ListNode(sum % 10);
            curr->next = head, head = curr; // head insertion
        }
        return head;
    }
};
// @lc code=end
