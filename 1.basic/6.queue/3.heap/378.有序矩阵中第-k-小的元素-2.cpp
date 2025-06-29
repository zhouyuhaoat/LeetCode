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
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for (int j = 0; j < (int)matrix[0].size(); j++) {
            pq.emplace(matrix[0][j], 0, j);
        }
        while (--k) {
            auto [_, x, y] = pq.top();
            pq.pop();
            if (x + 1 < (int)matrix.size()) {
                pq.emplace(matrix[x + 1][y], x + 1, y);
            }
        }
        return get<0>(pq.top());
    }
};
// @lc code=end
