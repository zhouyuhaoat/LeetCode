/*
 *   author:    zhouyuhao
 *   created:   2025-01-24 15:46:52
 *   modified:  2025-05-22 12:58:52
 *   project:   LeetCode of labuladong
 *   venue:     92, Shangrao
 */

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int lower_bound(vector<int>& A, int e) {
        int lo = 0, hi = A.size() - 1; // [lo, hi]
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] >= e) {
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = lower_bound(nums, target + 1) - 1;
        return first <= last ? vector<int>{first, last} : vector<int>{-1, -1};
    }
};
// @lc code=end
