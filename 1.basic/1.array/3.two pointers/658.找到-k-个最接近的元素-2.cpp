/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 16:08:14
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        int mi = distance(arr.begin(), ranges::lower_bound(arr, x)); // divine line
        int lo = mi, hi = mi;
        // [0, lo): smaller; [lo, hi): closest; [hi, size): larger
        while (k-- > 0) {
            if (lo <= 0) { // base case 1
                hi++;
            } else if (hi >= (int)arr.size()) { // base case 2
                lo--;
            } else if (x - arr[lo - 1] <= arr[hi] - x) { // if equal, lo - 1 < hi
                lo--;
            } else {
                hi++;
            }
        }
        return vector<int>{arr.begin() + lo, arr.begin() + hi};
    }
};
// @lc code=end
