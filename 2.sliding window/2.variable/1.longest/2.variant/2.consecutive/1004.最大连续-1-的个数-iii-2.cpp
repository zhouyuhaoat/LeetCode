/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:53:40
 *   modified:  2025-12-27 16:54:46
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, cnt = 0;
        for (int lo = 0, hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            cnt += nums[hi] == 0;
            while (cnt > k) {
                cnt -= nums[lo++] == 0;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
// @lc code=end
