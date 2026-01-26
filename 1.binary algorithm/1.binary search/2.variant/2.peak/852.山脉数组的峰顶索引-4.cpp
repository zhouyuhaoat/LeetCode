/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:27:37
 *   modified:  2026-01-24 16:23:22
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto it = ranges::adjacent_find(arr, greater<int>());
        return it - arr.begin();
    }
};
// @lc code=end
