/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 15:46:17
 * 	 modified: 	2024-10-26 15:58:31
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        int mi = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int lo = mi - 1, hi = mi; // negative, 0 + positive
        vector<int> res;
        while (lo >= 0 || hi < (int)nums.size()) { // 2-way merge
            if (lo < 0) {
                res.emplace_back(nums[hi] * nums[hi]);
                hi++;
            } else if (hi >= (int)nums.size()) {
                res.emplace_back(nums[lo] * nums[lo]);
                lo--;
            } else {
                int a = nums[lo] * nums[lo], b = nums[hi] * nums[hi];
                if (a < b) {
                    res.emplace_back(a);
                    lo--;
                } else {
                    res.emplace_back(b);
                    hi++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
