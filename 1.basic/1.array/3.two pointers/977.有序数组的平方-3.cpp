/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-13 10:05:59
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
        vector<int> res(nums.size());
        for (int lo = 0, hi = nums.size() - 1, pos = hi; lo <= hi; pos--) { // reverse merge
            int a = nums[lo] * nums[lo], b = nums[hi] * nums[hi];
            if (a < b) {
                res[pos] = b;
                hi--;
            } else {
                res[pos] = a;
                lo++;
            }
        }
        return res;
    }
};
// @lc code=end
