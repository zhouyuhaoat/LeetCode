/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-04 22:30:42
 * 	 modified: 	2024-11-04 22:36:02
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
        map<int, int> d; // balance tree: sorted
        for (vector<int>& t : trips) {
            int num = t[0], from = t[1], to = t[2];
            d[from] += num;
            d[to] -= num;
        }
        int s = 0;
        for (auto [_, v] : d) {
            s += v;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
