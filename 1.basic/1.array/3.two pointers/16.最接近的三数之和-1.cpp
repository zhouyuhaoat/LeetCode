/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-16 16:11:09
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        int res = 1e5, n = nums.size();
        ranges::sort(nums);
        auto update = [&](int x) {
            if (abs(res - target) > abs(x - target)) {
                res = x;
            }
        };
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target) return target;
                sum < target ? lo++ : hi--;
                update(sum);
            }
        }
        return res;
    }
};
// @lc code=end
