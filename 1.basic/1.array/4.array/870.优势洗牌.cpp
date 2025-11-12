/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-20 18:38:18
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        ranges::sort(nums1); // 君（己方）
        vector<int> idx(n); // 彼（对方）: value -> index
        ranges::iota(idx, 0);
        ranges::sort(idx, [&](int id1, int id2) {
            return nums2[id1] < nums2[id2];
        });
        vector<int> res(n);
        int lo = 0, hi = n - 1; // 彼下驷与彼上驷
        for (int num : nums1) { // 田忌赛马: greedy
            if (num > nums2[idx[lo]]) { // 君上驷与彼下驷
                res[idx[lo++]] = num;
            } else {
                res[idx[hi--]] = num; // 君下驷与彼上驷
            }
        }
        return res;
    }
};
// @lc code=end
