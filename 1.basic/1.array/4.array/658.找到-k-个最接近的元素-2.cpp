/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:50:04
 * 	 modified: 	2024-10-26 17:02:46
 * 	 project: 	LeetCode
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
        int mi = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int lo = mi - 1, hi = mi;
        // hi: possible not closer to x than lo if hi >> x
        while (k-- > 0) {
            if (lo < 0) {
                hi++;
            } else if (hi >= (int)arr.size()) {
                lo--;
            } else if (x - arr[lo] <= arr[hi] - x) { // if equal, lo < hi
                lo--;
            } else {
                hi++;
            }
        }
        return vector<int>(arr.begin() + lo + 1, arr.begin() + hi); // [lo + 1, hi) = [lo + 1, hi - 1]
    }
};
// @lc code=end
