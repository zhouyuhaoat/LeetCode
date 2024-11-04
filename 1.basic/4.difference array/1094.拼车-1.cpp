/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-04 22:12:06
 * 	 modified: 	2024-11-04 22:30:28
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
            int num = t[0], from = t[1], to = t[2]; // [from, to) = [from, to - 1]
            d[from] += num;
            d[to] -= num;
        }
        int s = 0;
        for (int v : d) {
            s += v;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
