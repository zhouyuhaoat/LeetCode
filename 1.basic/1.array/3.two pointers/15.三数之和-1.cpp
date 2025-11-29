/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 13:58:43
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        ranges::sort(nums); // prerequisite
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // duplicate
            if (nums[i] + nums[i + 1] + nums[i + 2] > target) break; // pruning
            if (nums[i] + nums[n - 1] + nums[n - 2] < target) continue; // pruning
            int lo = i + 1, hi = n - 1; // three sum -> fixed anchor -> two sum
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum > target) {
                    hi--;
                } else if (sum < target) {
                    lo++;
                } else {
                    res.emplace_back(vector<int>{nums[i], nums[lo], nums[hi]});
                    do {
                        hi--;
                    } while (lo < hi && nums[hi] == nums[hi + 1]); // duplicate
                    do {
                        lo++;
                    } while (lo < hi && nums[lo] == nums[lo - 1]); // duplicate
                }
            }
        }
        return res;
    }
};
// @lc code=end
