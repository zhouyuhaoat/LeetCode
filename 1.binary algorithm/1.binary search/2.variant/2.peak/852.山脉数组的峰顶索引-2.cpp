/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:07:41
 *   modified:  2026-01-24 16:24:35
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
        int lo = 0, hi = arr.size();
        auto it = ranges::find_if(views::iota(lo, hi), [&](int i) {
            return arr[i] > arr[i + 1];
        });
        return *it;
    }
};
// @lc code=end
