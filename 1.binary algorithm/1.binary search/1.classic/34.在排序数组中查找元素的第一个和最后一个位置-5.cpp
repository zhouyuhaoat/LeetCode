/*
 *   author:    zhouyuhao
 *   created:   2025-01-24 15:35:02
 *   modified:  2025-12-25 19:31:46
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
private:
    int upper_bound(vector<int>& A, int e) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] > e) { // first > e
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = upper_bound(nums, target - 1); // upper - epsilon = lower
        int last = upper_bound(nums, target);
        return first < last ? vector<int>{first, last - 1} : vector<int>{-1, -1};
    }
};
// @lc code=end
