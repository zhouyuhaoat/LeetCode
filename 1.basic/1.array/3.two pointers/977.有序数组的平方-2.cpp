/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 11:47:14
 * 	 modified: 	2025-02-16 19:13:14
 * 	 project: 	LeetCode of labuladong
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
        int mi = distance(nums.begin(), ranges::lower_bound(nums, 0));
        int lo = mi, hi = mi;
        // [0, lo): negative; [lo, hi): empty; [hi, inf): 0 + positive
        vector<int> res;
        while (lo > 0 || hi < (int)nums.size()) {
            if (lo <= 0) {
                res.emplace_back(nums[hi] * nums[hi++]);
            } else if (hi >= (int)nums.size()) {
                res.emplace_back(nums[--lo] * nums[lo]);
            } else {
                int a = nums[lo - 1] * nums[lo - 1], b = nums[hi] * nums[hi];
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
