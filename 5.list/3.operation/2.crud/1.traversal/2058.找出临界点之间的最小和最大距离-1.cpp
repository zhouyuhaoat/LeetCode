/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 22:01:22
 *   modified:  2026-01-18 09:55:03
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2058 lang=cpp
 *
 * [2058] 找出临界点之间的最小和最大距离
 */

// @lc code=start
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int minDist = INT_MAX, maxDist = 0;
        int firstIdx = -1, lastIdx = -1, idx = 1;
        auto isCritical = [](int prev, int curr, int next) {
            return curr > max(prev, next) || curr < min(prev, next);
        };
        ListNode *prev = head, *curr = head->next;
        while (curr->next) {
            ListNode *next = curr->next;
            if (isCritical(prev->val, curr->val, next->val)) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                }
                if (lastIdx != -1) {
                    minDist = min(minDist, idx - lastIdx);
                    maxDist = idx - firstIdx;
                }
                lastIdx = idx;
            }
            prev = curr, curr = next;
            idx++;
        }
        return maxDist == 0 ? vector<int>{-1, -1} : vector<int>{minDist, maxDist};
    }
};
// @lc code=end
