/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 23:44:51
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
        // dynamic programming -> two pointers
        // each element, static -> the whole array or the current element, dynamic
        // static: preprocessing -> dynamic: online update
        // hl: the highest left boundary, the leftmost higher or equal elevation
        // hr: the highest right boundary, the rightmost higher or equal elevation
        int res = 0, hl = 0, hr = 0, lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            hl = max(hl, height[lo]), hr = max(hr, height[hi]); // update before trap
            // although possibly not the highest one, but the higher or equal one
            // column by column: if higher, trap; if equal, no trap
            // container with most water: move the lower one, the area may be larger
            if (hl < hr) {
                res += hl - height[lo++];
            } else {
                res += hr - height[hi--];
            }
        }
        return res;
    }
};
// @lc code=end
