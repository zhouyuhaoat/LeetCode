/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-20 18:14:48
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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        for (int lo = 0, hi = 0; lo < (int)firstList.size() && hi < (int)secondList.size();) {
            int start = max(firstList[lo][0], secondList[hi][0]);
            int end = min(firstList[lo][1], secondList[hi][1]);
            if (start <= end) { // valid interval
                res.emplace_back(vector<int>{start, end});
            }
            firstList[lo][1] < secondList[hi][1] ? lo++ : hi++; // greedy: earlier end time
        }
        return res;
    }
};
// @lc code=end
