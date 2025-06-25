/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-20 18:57:54
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
            /*
                greedy
                - move bottleneck -> minimum loss -> maximum gain
                    - lower = min(lo, hi): bottleneck, can not compose a larger area with the other
                    - higher = max(lo, hi): possibly compose a larger area with the other side
                - move the lower one, the area may be larger
                - if move higher, the area must be smaller, so move lower
            */
            height[lo] < height[hi] ? lo++ : hi--;
        }
        return res;
    }
};
// @lc code=end
