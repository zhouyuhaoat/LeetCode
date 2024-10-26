/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 14:41:19
 * 	 modified: 	2024-10-26 14:52:17
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // overflow
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int lo = j + 1, hi = n - 1;
                while (lo < hi) {
                    long long sum = (long long)nums[i] + nums[j] + nums[lo] + nums[hi];
                    if (sum < target) {
                        lo++;
                    } else if (sum > target) {
                        hi--;
                    } else {
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[lo], nums[hi]});
                        do {
                            lo++;
                        } while (lo < hi && nums[lo] == nums[lo - 1]);
                        do {
                            hi--;
                        } while (lo < hi && nums[hi] == nums[hi + 1]);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
