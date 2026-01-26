/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:10:59
 *   modified:  2025-12-23 10:24:51
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto isRight = [&](int mi) {
            if (nums[mi] > nums.back()) {
                return target > nums.back() && nums[mi] >= target;
            } else {
                return target > nums.back() || nums[mi] >= target;
            }
        };

        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (isRight(mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return nums[hi] == target ? hi : -1;
    }
};
// @lc code=end
