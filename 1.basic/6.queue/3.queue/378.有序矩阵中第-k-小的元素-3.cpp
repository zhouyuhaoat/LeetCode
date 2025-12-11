/*
 *   author:    zhouyuhao
 *   created:   2025-03-03 08:53:15
 *   modified:  2025-03-03 09:04:26
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < m; i++) {
            pq.emplace(-matrix[i][0], i, 0); // negative
        }
        while (--k) {
            auto [_, i, j] = pq.top();
            pq.pop();
            if (j + 1 < n) {
                pq.emplace(-matrix[i][j + 1], i, j + 1);
            }
        }
        return -get<0>(pq.top());
    }
};
// @lc code=end
