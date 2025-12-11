/*
 *   author:    zhouyuhao
 *   created:   2024-12-12 12:44:54
 *   modified:  2025-12-04 20:36:23
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
    int partition(vector<int>& A, int lo, int hi) { // greater
        int pivot = lo;
        swap(A[pivot], A[lo + rand() % (hi - lo)]);
        while (lo < hi) {
            do {
                hi--;
            } while (lo < hi && A[hi] < A[pivot]);
            do {
                lo++;
            } while (lo < hi && A[lo] > A[pivot]);
            if (lo < hi) swap(A[lo], A[hi]);
        }
        swap(A[pivot], A[hi]);
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
        return quickSelect(nums, k - 1);
    }
};
// @lc code=end
