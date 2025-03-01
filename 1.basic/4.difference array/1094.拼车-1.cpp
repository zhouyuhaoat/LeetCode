/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:09
 *   modified:  2025-02-28 16:36:14
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v;
        for (vector<int>& t : trips) {
            v.emplace_back(t[1], t[0]);
            v.emplace_back(t[2], -t[0]);
            // subtract positive -> add negative
        }
        ranges::sort(v);
        int cur = 0;
        for (pair<int, int>& p : v) {
            cur += p.second;
            if (cur > capacity) return false;
        }
        return true;
    }
};
// @lc code=end
