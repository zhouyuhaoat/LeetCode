/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 18:19:08
 * 	 modified: 	2024-10-26 18:32:53
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        int res = -1, dif = INT_MAX, n = nums.size();
        auto update = [&](int x) {
            if (abs(x - target) < dif) {
                dif = abs(x - target);
                res = x; // since absolute value, res != dif + target
            }
        };
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int sum = nums[i] + nums[i + 1] + nums[i + 2];
            if (sum > target) { // pruning
                update(sum);
                break;
            }
            sum = nums[i] + nums[n - 1] + nums[n - 2];
            if (sum < target) { // pruning
                update(sum);
                continue;
            }
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target) return target;
                update(sum);
                sum < target ? lo++ : hi--;
            }
        }
        return res;
    }
};
// @lc code=end
