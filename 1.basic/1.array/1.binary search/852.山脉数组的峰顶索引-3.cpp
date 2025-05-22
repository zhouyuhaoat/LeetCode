/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:27:37
 *   modified:  2025-05-22 09:39:46
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
        vector<int> idx(arr.size() - 2);
        ranges::iota(idx, 1);
        auto it = ranges::find_if(idx, [&](int i) {
            return arr[i] > arr[i + 1];
        });
        return *it;
    }
};
// @lc code=end
