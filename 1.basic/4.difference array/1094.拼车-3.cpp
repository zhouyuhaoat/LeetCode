/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:09
 *   modified:  2025-02-28 17:31:33
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
        int d[1001] = {};
        for (vector<int>& t : trips) {
            int num = t[0], from = t[1], to = t[2];
            d[from] += num, d[to] -= num;
        }
        int cur = 0;
        for (int v : d) {
            cur += v;
            if (cur > capacity) return false;
        }
        return true;
    }
};
// @lc code=end
