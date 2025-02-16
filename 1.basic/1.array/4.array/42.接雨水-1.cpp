/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-13 10:08:06
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        // dynamic programming: preprocess
        // prefix + suffix decomposition
        int n = height.size(), res = 0;
        vector<int> lo(n), hi(n); // inference from neighbour
        for (int i = 1; i < n; i++) {
            lo[i] = max(lo[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            hi[i] = max(hi[i + 1], height[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            int tmp = min(lo[i], hi[i]) - height[i]; // column by column
            res += tmp > 0 ? tmp : 0;
        }
        return res;
    }
};
// @lc code=end
