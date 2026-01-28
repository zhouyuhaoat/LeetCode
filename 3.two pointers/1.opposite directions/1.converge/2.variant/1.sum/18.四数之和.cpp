/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-12-28 14:41:03
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        ranges::sort(nums);
        auto sum4 = [&](int a, int b, int c, int d) {
            return static_cast<long long>(nums[a]) + nums[b] + nums[c] + nums[d]; // overflow
        };
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (sum4(i, i + 1, i + 2, i + 3) > target) break;
            if (sum4(i, n - 1, n - 2, n - 3) < target) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (sum4(i, j, j + 1, j + 2) > target) break;
                if (sum4(i, j, n - 1, n - 2) < target) continue;
                int lo = j + 1, hi = n - 1; // four sum -> fixes -> two sum
                while (lo < hi) {
                    long long sum = sum4(i, j, lo, hi);
                    if (sum > target) {
                        hi--;
                    } else if (sum < target) {
                        lo++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        do {
                            hi--;
                        } while (lo < hi && nums[hi] == nums[hi + 1]);
                        do {
                            lo++;
                        } while (lo < hi && nums[lo] == nums[lo - 1]);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
