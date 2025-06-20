/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 15:43:05
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mi = distance(nums.begin(), ranges::lower_bound(nums, 0)); // divine line
        int lo = mi - 1, hi = mi;
        // [0, lo + 1) = [0, lo]: negative; [lo + 1, hi): empty; [hi, inf): 0 + positive
        vector<int> res;
        while (lo >= 0 || hi < (int)nums.size()) { // 2-way merge
            if (lo < 0) {
                res.emplace_back(nums[hi] * nums[hi++]);
            } else if (hi >= (int)nums.size()) {
                res.emplace_back(nums[lo] * nums[lo--]);
            } else {
                int power1 = nums[lo] * nums[lo], power2 = nums[hi] * nums[hi];
                if (power1 < power2) {
                    res.emplace_back(power1);
                    lo--;
                } else {
                    res.emplace_back(power2);
                    hi++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
