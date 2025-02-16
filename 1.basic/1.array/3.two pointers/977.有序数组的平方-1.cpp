/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-16 19:10:56
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        int mi = distance(nums.begin(), ranges::lower_bound(nums, 0)); // divine line
        int lo = mi - 1, hi = mi;
        // [0, lo + 1) = [0, lo]: negative; [lo + 1, hi): empty; [hi, inf): 0 + positive
        vector<int> res;
        while (lo >= 0 || hi < (int)nums.size()) { // 2-way merge
            if (lo < 0) {
                res.emplace_back(nums[hi] * nums[hi++]);
            } else if (hi >= (int)nums.size()) {
                res.emplace_back(nums[lo] * nums[lo--]);
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
