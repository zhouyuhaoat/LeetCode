/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 18:28:03
 *   modified:  2026-01-17 21:29:48
 *   project:   LeetCode
 *   venue:     A20, Harbin
 */

/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
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
    int getDecimalValue(ListNode *head) {
        return stoi(toString(head), nullptr, 2);
    }
};
// @lc code=end
