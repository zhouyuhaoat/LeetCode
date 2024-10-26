/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:47:20
 * 	 modified: 	2024-10-26 16:47:51
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, res.begin());
        nums1 = res;
    }
};
// @lc code=end
