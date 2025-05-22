/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:07:41
 *   modified:  2025-05-22 09:38:54
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
        for (int i = 1; i < (int)arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) return i;
        }
        return 0;
    }
};
// @lc code=end
