/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:27:37
 *   modified:  2025-05-22 09:40:18
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
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (arr[mi] > arr[mi + 1]) { // first arr[i] > arr[i + 1]
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }
};
// @lc code=end
