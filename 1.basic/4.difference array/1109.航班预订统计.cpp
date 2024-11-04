/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-04 22:39:39
 * 	 modified: 	2024-11-04 22:51:48
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
        vector<int> diff(n + 2);
        for (vector<int>& b : bookings) {
            int first = b[0], last = b[1], seats = b[2];
            diff[first] += seats;
            diff[last + 1] -= seats;
        }
        int s = 0;
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            s += diff[i];
            res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end
