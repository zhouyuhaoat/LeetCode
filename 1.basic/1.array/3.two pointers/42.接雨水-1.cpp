/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 18:36:14
 * 	 modified: 	2024-10-26 18:45:05
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        int n = height.size(), res = 0;
        vector<int> lo(n), hi(n); // inference from the neighbour
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
