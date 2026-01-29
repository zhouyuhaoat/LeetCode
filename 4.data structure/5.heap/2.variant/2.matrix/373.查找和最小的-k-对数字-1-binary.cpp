/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 21:25:47
 *   modified:  2025-03-03 08:55:16
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
        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min((int)nums1.size(), k); i++) { // multi-way merge
            pq.emplace(i, 0);
        }
        vector<vector<int>> res;
        while (k--) {
            auto [i, j] = pq.top();
            pq.pop();
            res.push_back(vector<int>{nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) {
                pq.emplace(i, j + 1);
            }
        }
        return res;
    }
};
// @lc code=end
