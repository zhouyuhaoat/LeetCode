/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 11:47:14
 * 	 modified: 	2025-02-16 19:43:15
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	914, Harbin
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
        int lo = mi - 1, hi = mi;
        // [0, lo + 1) = [0, lo]: smaller; [lo + 1, hi): closest; [hi, inf): not smaller
        while (k-- > 0) {
            if (lo < 0) { // base or boundary
                hi++;
            } else if (hi >= (int)arr.size()) {
                lo--;
            } else if (x - arr[lo] <= arr[hi] - x) { // if equal, lo < hi
                lo--;
            } else {
                hi++;
            }
        }
        return vector<int>{arr.begin() + lo + 1, arr.begin() + hi};
    }
};
// @lc code=end
