/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 15:46:17
 * 	 modified: 	2024-10-26 16:00:06
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
