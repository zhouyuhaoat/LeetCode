/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 15:34:28
 *   modified:  2025-12-04 20:33:44
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
    int partition(vector<int>& A, int lo, int hi) { // Lomuto: LGU
        int pivot = hi - 1;
        swap(A[lo + rand() % (hi - lo)], A[pivot]);
        for (int hi = lo; hi < pivot; hi++) {
            if (A[hi] < A[pivot]) {
                swap(A[lo++], A[hi]);
            }
        }
        swap(A[lo], A[pivot]);
        return lo;
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
