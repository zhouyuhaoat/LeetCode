/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 19:14:55
 * 	 modified: 	2024-10-26 19:16:54
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
        int res = 0, level = 0; // already safe level
        // maximum lower up to the current one, update when meet a higher level
        int lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            int lower = height[lo] < height[hi] ? height[lo++] : height[hi--];
            // the lower one of the leftmost/rightmost elevation
            level = max(level, lower);
            res += level - lower; // bound of column: upper - lower
        }
        return res;
    }
};
// @lc code=end
