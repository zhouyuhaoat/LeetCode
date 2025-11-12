/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-20 19:04:25
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
        vector<int> left(n), right(n); // boundaries: max height to the left and right
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
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
