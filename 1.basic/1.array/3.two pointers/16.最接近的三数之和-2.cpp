/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 13:59:18
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = -1, diff = INT_MAX, n = nums.size();
        ranges::sort(nums);
        auto update = [&](int x) {
            if (abs(x - target) < diff) {
                diff = abs(x - target);
                res = x; // res != diff + target
            }
        };
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int sum = nums[i] + nums[i + 1] + nums[i + 2];
            if (sum > target) {
                update(sum); // update even pruning
                break;
            }
            sum = nums[i] + nums[n - 1] + nums[n - 2];
            if (sum < target) {
                update(sum); // update even pruning
                continue;
            }
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target) return target;
                sum < target ? lo++ : hi--;
                update(sum);
            }
        }
        return res;
    }
};
// @lc code=end
