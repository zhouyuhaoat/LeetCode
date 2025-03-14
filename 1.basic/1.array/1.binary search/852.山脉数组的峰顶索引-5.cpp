/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 22:27:37
 * 	 modified: 	2025-02-11 23:55:07
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        auto it = adjacent_find(arr.begin() + 1, arr.end(), greater<int>());
        return distance(arr.begin(), it);
    }
};
// @lc code=end
