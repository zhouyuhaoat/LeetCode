/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 21:33:18
 *   modified:  2025-03-03 08:51:47
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.emplace(-nums1[i] - nums2[0], i, 0);
            // maxheap -> flip by negative -> minheap
        }
        vector<vector<int>> res;
        while (k--) {
            auto [_, i, j] = pq.top();
            pq.pop();
            res.emplace_back(vector<int>{nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) {
                pq.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
            }
        }
        return res;
    }
};
// @lc code=end
