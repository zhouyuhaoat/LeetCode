/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-18 17:56:04
 * 	 modified: 	2025-02-19 10:28:25
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
        vector<int> res(nums.size());
        for (int lo = 0, hi = nums.size() - 1, pos = hi; lo <= hi; pos--) {
            // multiply twice: compare square values directly
            // multiply once: compare additive inverse and original value indirectly since sorted
            int a = nums[lo], b = nums[hi];
            if (-a > b) {
                res[pos] = a * a;
                lo++;
            } else {
                res[pos] = b * b;
                hi--;
            }
        }
        return res;
    }
};
// @lc code=end
