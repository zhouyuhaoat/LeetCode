/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 18:33:13
 * 	 modified: 	2024-10-26 18:34:36
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
        int res = 1e5;
        auto update = [&](int x) {
            if (abs(x - target) < abs(res - target)) {
                res = x;
            }
        };
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1, hi = (int)nums.size() - 1;
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
