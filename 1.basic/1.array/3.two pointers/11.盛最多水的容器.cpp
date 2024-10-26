/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:01:00
 * 	 modified: 	2024-10-26 16:04:08
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int lo = 0, hi = height.size() - 1; lo < hi;) {
            res = max(res, min(height[lo], height[hi]) * (hi - lo));
            // greedy: move min(i, j), minimum loss, maximum gain
            if (height[lo] < height[hi]) {
                lo++;
            } else {
                hi--;
            }
        }
        return res;
    }
};
// @lc code=end
