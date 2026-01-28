/*
 *   author:    zhouyuhao
 *   created:   2025-11-14 12:53:15
 *   modified:  2025-11-14 16:01:44
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int target = 0, n = nums.size();
        ranges::sort(nums);
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > target) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] < target) continue;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum > target) {
                    hi--;
                } else if (sum < target) {
                    lo++;
                } else {
                    if (lo == i + 1 || nums[lo] != nums[lo - 1]) { // valid -> judge
                        res.push_back({nums[i], nums[lo], nums[hi]});
                    }
                    hi--, lo++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
