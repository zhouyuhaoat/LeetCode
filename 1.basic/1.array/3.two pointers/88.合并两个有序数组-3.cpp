/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 15:25:49
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        while (j < n && k < m) {
            nums1[i++] = nums2[j] < nums3[k] ? nums2[j++] : nums3[k++];
        }
        while (j < n) {
            nums1[i++] = nums2[j++];
        }
        while (k < m) {
            nums1[i++] = nums3[k++];
        }
    }
};
// @lc code=end
