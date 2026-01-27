/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:24:47
 *   modified:  2025-12-16 18:32:04
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, sum = 0;
        for (int lo = 0, hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            sum += nums[hi];
            while (sum >= target) {
                res = min(res, hi - lo + 1);
                sum -= nums[lo++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
