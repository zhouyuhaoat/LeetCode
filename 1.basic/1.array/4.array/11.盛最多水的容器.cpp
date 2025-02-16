/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 23:32:09
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        // container with most water: move the lower one, the area may be larger
        int res = 0;
        for (int lo = 0, hi = height.size() - 1; lo < hi;) { // container: two columns
            // two pointers -> middle: all the possible solutions are included in the search space
            // each move of the pointers: the search space is reduced
            res = max(res, min(height[lo], height[hi]) * (hi - lo));
            // greedy: move bottleneck -> minimum loss -> maximum gain
            // bottleneck: min(lo, hi), can not compose a larger area with the other side
            // higher min(lo, hi): possibly compose a larger area with the other side
            // if move max(lo, hi), the area must be smaller, so move min(lo, hi)
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
