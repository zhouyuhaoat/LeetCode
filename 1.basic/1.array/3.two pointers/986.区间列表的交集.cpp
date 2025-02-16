/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-16 19:21:19
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < (int)firstList.size() && j < (int)secondList.size();) {
            int lo = max(firstList[i][0], secondList[j][0]);
            int hi = min(firstList[i][1], secondList[j][1]);
            if (lo <= hi) { // interval merge
                res.emplace_back(vector<int>{lo, hi});
            }
            hi == firstList[i][1] ? i++ : j++;
            // move the interval with smaller end-point, not begin-point,
            // since the interval may intersect with the other interval
            // if the end-point is the same, move both
        }
        return res;
    }
};
// @lc code=end
