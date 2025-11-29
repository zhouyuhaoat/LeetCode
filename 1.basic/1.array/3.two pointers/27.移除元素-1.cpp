/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 14:01:49
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lo = 0;
        // [0, lo): != val; [lo, hi): == val; [hi, size): unknown
        for (int hi = lo; hi < (int)nums.size(); hi++) {
            if (nums[hi] != val) {
                nums[lo++] = nums[hi];
            }
        }
        return lo;
    }
};
// @lc code=end
