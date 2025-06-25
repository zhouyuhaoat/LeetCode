/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-21 22:12:51
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, left = 0, right = 0; // boundaries: max height to the left and right
        int lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            left = max(left, height[lo]), right = max(right, height[hi]);
            // greedy: move the lower one
            if (left < right) {
                res += left - height[lo++];
            } else {
                res += right - height[hi--];
            }
        }
        return res;
    }
};
// @lc code=end
