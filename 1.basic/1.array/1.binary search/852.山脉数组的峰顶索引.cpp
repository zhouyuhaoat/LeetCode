/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 20:52:24
 * 	 modified: 	2024-10-24 21:01:49
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (arr[mi] > arr[mi + 1]) {
                hi = mi; // [hi, arr.size() - 1): arr[i] > arr[i + 1]
            } else {
                lo = mi + 1; // [0, lo): arr[i] <= arr[i + 1]
            }
        }
        return hi; // first arr[i] > arr[i + 1]
    }
};
// @lc code=end
