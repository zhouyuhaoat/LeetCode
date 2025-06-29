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
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        /*
            traverse in the grid or matrix [0, i) x [0, j)
            1. right and down in the grid
                - (0, 0) -> (i - 1, j - 1)
            2. only right in the grid
                - (0 ... i - 1, 0) -> (0 ... i - 1, j - 1)
            3. only down in the grid
                - (0, 0 ... j - 1) -> (i - 1, 0 ... j - 1)
            - transpose the grid
                - down in the grid is the same as right in the grid
            - merge optimization
                - use priority queue to optimize multi-way merge, as merge multiple sorted list
        */
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.emplace(i, 0);
        }
        vector<vector<int>> res;
        while (k--) {
            auto [i, j] = pq.top();
            pq.pop();
            res.emplace_back(vector<int>{nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) {
                pq.emplace(i, j + 1);
            }
        }
        return res;
    }
};
// @lc code=end
