/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 18:54:47
 * 	 modified: 	2024-10-26 19:06:20
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
        // dynamic programming -> two pointers
        int res = 0, hl = 0, hr = 0; // each element -> only one
        int lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            hl = max(hl, height[lo]), hr = max(hr, height[hi]);
            // although not necessarily the highest one, but the higher or equal one
            if (hl < hr) {
                res += hl - height[lo]; // column of lo
                lo++;
            } else {
                res += hr - height[hi]; // column of hi
                hi--;
            }
        }
        return res;
    }
};
// @lc code=end
