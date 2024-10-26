/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:13:49
 * 	 modified: 	2024-10-26 21:49:40
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        for (int a = 0, b = 0; a < (int)firstList.size() && b < (int)secondList.size();) {
            int lo = max(firstList[a][0], secondList[b][0]);
            int hi = min(firstList[a][1], secondList[b][1]);
            if (lo <= hi) { // interval merge
                res.emplace_back(vector<int>{lo, hi});
            }
            if (hi == firstList[a][1]) { // end-point, not begin-point
                a++;
            } else {
                b++;
            }
        }
        return res;
    }
};
// @lc code=end
