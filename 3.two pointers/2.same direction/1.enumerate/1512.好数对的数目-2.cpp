/*
 *   author:    zhouyuhao
 *   created:   2025-12-24 11:05:21
 *   modified:  2025-12-25 08:52:22
 *   project:   LeetCode of primers
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        for (int hi = 0; hi < (int)nums.size(); hi++) { // fix hi, move lo
            for (int lo = 0; lo < hi; lo++) {
                if (nums[lo] == nums[hi]) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
