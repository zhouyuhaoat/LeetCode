/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 14:06:12
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        int k = 2, lo = k;
        if ((int)nums.size() <= k) return nums.size();
        // [0, lo): at most k; [lo, hi): more than k; [hi, size): unknown
        for (int hi = k; hi < (int)nums.size(); hi++) {
            if (nums[hi] != nums[lo - k]) {
                nums[lo++] = nums[hi];
            }
        }
        return lo;
    }
};
// @lc code=end
