/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:27:37
 *   modified:  2025-05-22 09:40:31
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
        auto it = ranges::partition_point(views::iota(lo, hi), [&](int mi) {
            return arr[mi] < arr[mi + 1]; // first false
        });
        return *it;
    }
};
// @lc code=end
