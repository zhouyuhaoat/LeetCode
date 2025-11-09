/*
 *   author:    zhouyuhao
 *   created:   2025-01-23 23:47:22
 *   modified:  2025-05-22 12:57:45
 *   project:   LeetCode of labuladong
 *   venue:     501, Shangrao
 */

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
private:
    int lower_bound(vector<int>& A, int e) {
        int lo = 0, hi = A.size(); // [lo, hi)
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] >= e) { // first >= e
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = lower_bound(nums, target + 1) - 1;
        return first <= last ? vector<int>{first, last} : vector<int>{-1, -1};
    }
};
// @lc code=end
