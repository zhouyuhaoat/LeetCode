/*
 *   author:    zhouyuhao
 *   created:   2025-01-27 20:51:28
 *   modified:  2025-05-22 13:06:47
 *   project:   LeetCode of labuladong
 *   venue:     501, Shangrao
 */

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
private:
    int binary_search(vector<int>& A, int e) {
        int lo = 0, hi = A.size(); // [lo, hi)
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] > e) {
                hi = mi;
            } else if (A[mi] < e) {
                lo = mi + 1;
            } else {
                return mi;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target);
    }
};
// @lc code=end
