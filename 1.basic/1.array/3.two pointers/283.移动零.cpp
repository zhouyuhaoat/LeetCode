/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-16 18:53:24
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
                // swap: unstable for zero
                // lo++: stable for non-zero
            }
        }
    }
};
// @lc code=end
