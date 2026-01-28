/*
 *   author:    zhouyuhao
 *   created:   2025-11-14 23:15:54
 *   modified:  2025-11-14 23:24:04
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 2, lo = dup;
        // [0, lo): at most; [lo, hi): more than; [hi, size): unknown
        for (int hi = lo; hi < (int)nums.size(); hi++) {
            if (nums[hi] != nums[lo - dup]) {
                nums[lo++] = nums[hi];
            }
        }
        return min(lo, (int)nums.size());
    }
};
// @lc code=end
