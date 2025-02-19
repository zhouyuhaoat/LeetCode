/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-18 23:19:07
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lo = 0;
        // [0, lo): != 0; [lo, hi): == 0; [hi, inf): unknown
        for (int hi = 0; hi < (int)nums.size(); hi++) {
            if (nums[hi] != 0) {
                swap(nums[lo++], nums[hi]);
                // swap: unstable for zero; lo++: stable for non-zero
                // swap between begins of [lo, hi) and [hi, inf)
                // after swap, [0, lo) expand by 1, [hi, inf) shrink by 1
                // [lo, hi) move the first zero to end, as shift right by 1
            }
        }
    }
};
// @lc code=end
