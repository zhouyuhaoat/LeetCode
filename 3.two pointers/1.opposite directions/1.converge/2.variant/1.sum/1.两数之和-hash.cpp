/*
 *   author:    zhouyuhao
 *   created:   2025-12-22 10:56:45
 *   modified:  2025-12-22 22:51:46
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx(nums.size());
        ranges::iota(idx, 0);
        ranges::sort(idx, {}, [&](int i) {
            return nums[i];
        });
        int lo = 0, hi = nums.size() - 1; // two sum
        while (lo < hi) {
            int sum = nums[idx[lo]] + nums[idx[hi]];
            if (sum > target) {
                hi--;
            } else if (sum < target) {
                lo++;
            } else {
                return {idx[lo], idx[hi]};
            }
        }
        return {};
    }
};
// @lc code=end
