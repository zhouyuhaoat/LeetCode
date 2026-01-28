/*
 *   author:    zhouyuhao
 *   created:   2025-12-28 10:58:59
 *   modified:  2025-12-28 11:03:30
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size(); // diverge -> reverse -> converge
        // [0, lo): smaller; [lo, hi): closest; [hi, size): larger
        while (hi - lo > k) {
            if (abs(arr[lo] - x) <= abs(arr[hi - 1] - x)) {
                hi--;
            } else {
                lo++;
            }
        }
        return vector<int>{arr.begin() + lo, arr.begin() + hi};
    }
};
// @lc code=end
