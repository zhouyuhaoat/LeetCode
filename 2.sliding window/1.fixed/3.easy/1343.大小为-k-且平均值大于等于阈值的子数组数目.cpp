/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 20:08:02
 *   modified:  2025-12-25 20:09:22
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0, sum = 0, bound = threshold * k;
        for (int hi = 0; hi < (int)arr.size(); hi++) { // [lo, hi]
            sum += arr[hi];
            int lo = hi - k + 1;
            if (lo >= 0) {
                if (sum >= bound) {
                    res++;
                }
                sum -= arr[lo];
            }
        }
        return res;
    }
};
// @lc code=end
