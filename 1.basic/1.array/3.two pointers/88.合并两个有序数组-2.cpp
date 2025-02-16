/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-13 10:02:09
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
