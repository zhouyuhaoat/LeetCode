/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2026-01-28 15:58:15
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
        int n = height.size();
        vector<int> left(n), right(n); // bound: max height to the left and right
        // dynamic programming: prefix and suffix decomposition
        for (int i = 0; i < n - 1; i++) {
            left[i + 1] = max(left[i], height[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            right[i - 1] = max(right[i], height[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int col = min(left[i], right[i]) - height[i]; // column by column
            res += col > 0 ? col : 0;
        }
        return res;
    }
};
// @lc code=end
