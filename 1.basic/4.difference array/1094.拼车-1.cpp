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
        vector<pair<int, int>> seats; // {index, change}
        for (auto trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            seats.emplace_back(from, num);
            seats.emplace_back(to, -num);
        }
        ranges::sort(seats);
        int cap = 0; // prefix sum
        for (auto [_, val] : seats) {
            cap += val;
            if (cap > capacity) return false;
        }
        return true;
    }
};
// @lc code=end
