/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:27:37
 *   modified:  2025-05-22 09:53:17
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
        return ranges::max_element(arr) - arr.begin();
    }
};
// @lc code=end
