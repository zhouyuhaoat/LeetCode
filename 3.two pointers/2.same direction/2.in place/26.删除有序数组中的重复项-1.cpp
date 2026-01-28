/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 14:05:38
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 1, lo = dup;
        // [0, lo): unique; [lo, hi): duplicate; [hi, size): unknown
        for (int hi = lo; hi < (int)nums.size(); hi++) {
            if (nums[hi] != nums[lo - dup]) {
                nums[lo++] = nums[hi];
            }
        }
        return lo;
    }
};
// @lc code=end
