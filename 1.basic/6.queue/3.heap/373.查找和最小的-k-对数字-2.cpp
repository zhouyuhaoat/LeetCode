/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 12:13:13
 *   modified:  2025-03-03 08:51:05
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
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int j = 0; j < min((int)nums2.size(), k); j++) {
            pq.emplace(0, j);
        }
        vector<vector<int>> res;
        while (k--) {
            auto [i, j] = pq.top();
            pq.pop();
            res.emplace_back(vector<int>{nums1[i], nums2[j]});
            if (i + 1 < (int)nums1.size()) {
                pq.emplace(i + 1, j);
            }
        }
        return res;
    }
};
// @lc code=end
