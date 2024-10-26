/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:47:20
 * 	 modified: 	2024-10-26 16:48:28
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
        vector<int> nums3(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0, k = 0;
        while (j < m && k < n) {
            if (nums3[j] < nums2[k]) {
                nums1[i++] = nums3[j++];
            } else {
                nums1[i++] = nums2[k++];
            }
        }
        while (j < m) {
            nums1[i++] = nums3[j++];
        }
        while (k < n) {
            nums1[i++] = nums2[k++];
        }
    }
};
// @lc code=end
