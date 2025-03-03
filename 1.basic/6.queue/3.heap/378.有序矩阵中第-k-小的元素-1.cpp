/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 21:53:35
 *   modified:  2025-03-03 08:55:27
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
        struct point {
            int v, x, y;
            point(int v, int x, int y) : v(v), x(x), y(y) {
            }
            bool operator<(const point& a) const {
                return this->v > a.v;
            }
        };
        // [0, i) x [0, j): traverse in the grid/matrix
        // 1. (0, 0) -> (i - 1, j - 1): right or down in the grid
        // 2. (0 ... i - 1, 0) -> (0 ... i - 1, j - 1): only right in the grid
        // 3. (0, 0 ... j - 1) -> (i - 1, 0 ... j - 1): only down in the grid
        // rotate the grid, down in the grid is the same as right in the grid
        // merge sort: use priority queue to optimize k-way merge, as merge k sorted list
        priority_queue<point> pq;
        for (int i = 0; i < (int)matrix.size(); i++) {
            pq.emplace(matrix[i][0], i, 0);
        }
        while (--k) {
            point t = pq.top();
            pq.pop();
            if (t.y + 1 < (int)matrix[0].size()) {
                pq.emplace(matrix[t.x][t.y + 1], t.x, t.y + 1);
            }
        }
        return pq.top().v;
    }
};
// @lc code=end
