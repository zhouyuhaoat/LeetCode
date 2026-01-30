/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-27 19:02:21
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
class Solution {
private:
    vector<int> toVector(ListNode *head) {
        vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        return vec;
    }

    bool helper(vector<int>& vec) {
        for (int lo = 0, hi = (int)vec.size() - 1; lo < hi; lo++, hi--) {
            if (vec[lo] != vec[hi]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head) {
        vector<int> vec = toVector(head);
        return helper(vec);
    }
};
// @lc code=end
