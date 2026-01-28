/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 14:12:14
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        int lo = 0, val = 0;
        // [0, lo): !0; [lo, hi): 0; [hi, size): unknown
        for (int hi = lo; hi < (int)nums.size(); hi++) {
            if (nums[hi] != val) {
                swap(nums[lo++], nums[hi]);
            }
        }
    }
};
// @lc code=end
