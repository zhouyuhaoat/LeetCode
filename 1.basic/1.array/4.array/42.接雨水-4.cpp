/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 23:47:55
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
        int res = 0, level = 0; // already safe level
        // safe: the lower one of the highest left boundary (hl) and the highest right boundary (hr)
        // safe: two boundary -> one boundary
        int lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            // container with most water: move the lower one, the area may be larger
            int lower = height[lo] < height[hi] ? height[lo++] : height[hi--];
            level = max(level, lower); // safe: maximum lower up to the current one
            // more and more safe: increase, or the same, no decrease
            res += level - lower; // column by column: safe - current
        }
        return res;
    }
};
// @lc code=end
