/*
 *   author:    zhouyuhao
 *   created:   2025-12-26 12:23:01
 *   modified:  2025-12-27 16:17:48
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, cnt = 0, k = 1;
        for (int lo = 0, hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            cnt += nums[hi] == 0;
            while (cnt > k) {
                cnt -= nums[lo++] == 0;
            }
            res = max(res, hi - lo + 1);
        }
        return res - 1;
    }
};
// @lc code=end
