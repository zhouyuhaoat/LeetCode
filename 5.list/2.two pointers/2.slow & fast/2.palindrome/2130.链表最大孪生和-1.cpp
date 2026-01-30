/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:36:43
 *   modified:  2026-01-18 20:32:22
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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

    int maxTwinSum(vector<int>& vec) {
        int sum = -1;
        for (int lo = 0, hi = vec.size() - 1; lo < hi; lo++, hi--) {
            sum = max(sum, vec[lo] + vec[hi]);
        }
        return sum;
    }

public:
    int pairSum(ListNode *head) {
        vector<int> vec = toVector(head);
        return maxTwinSum(vec);
    }
};
// @lc code=end
