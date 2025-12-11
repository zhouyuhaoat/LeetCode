/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 15:34:28
 *   modified:  2025-12-04 20:34:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
private:
    int partition(vector<int>& A, int lo, int hi) { // Hoare: DUP
        swap(A[lo], A[lo + rand() % (hi - lo)]);
        int pivot = A[lo];
        while (lo < hi) {
            do {
                hi--;
            } while (lo < hi && A[hi] > pivot);
            if (lo < hi) A[lo] = A[hi];
            do {
                lo++;
            } while (lo < hi && A[lo] < pivot);
            if (lo < hi) A[hi] = A[lo];
        }
        A[hi] = pivot;
        return hi;
    }

    int quickSelect(vector<int>& A, int k) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            int mi = partition(A, lo, hi);
            if (mi >= k) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return A[lo];
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, (int)nums.size() - k);
    }
};
// @lc code=end
