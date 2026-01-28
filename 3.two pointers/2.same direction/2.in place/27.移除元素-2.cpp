/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 14:18:32
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
        int hi = nums.size(); // reverse remove
        // [0, lo): !val; [lo, hi): unknown; [hi, size): val
        for (int lo = 0; lo < hi; lo++) {
            if (nums[lo] == val) {
                nums[lo--] = nums[--hi];
            }
        }
        return hi;
    }
};
// @lc code=end
