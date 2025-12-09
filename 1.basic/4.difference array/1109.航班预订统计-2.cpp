/*
 *   author:    zhouyuhao
 *   created:   2025-12-02 23:37:05
 *   modified:  2025-12-03 15:24:28
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        for (auto booking : bookings) {
            int first = booking[0] - 1, last = booking[1] - 1, val = booking[2];
            nums[first] += val;
            if (last + 1 < n) {
                nums[last + 1] -= val;
            }
        }
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
// @lc code=end
