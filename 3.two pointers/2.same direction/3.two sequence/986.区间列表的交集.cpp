/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-12-28 15:25:18
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2) {
        vector<vector<int>> res;
        int m = list1.size(), n = list2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            int start = max(list1[i][0], list2[j][0]), end = min(list1[i][1], list2[j][1]); // intersect
            if (start <= end) { // valid interval
                res.push_back({start, end});
            }
            list1[i][1] < list2[j][1] ? i++ : j++; // earlier end time
        }
        return res;
    }
};
// @lc code=end
