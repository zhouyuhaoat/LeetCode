/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 15:32:08
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
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) { // j cannot be negative
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
// @lc code=end
