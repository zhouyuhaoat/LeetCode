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
        struct Point {
            int val, x, y;
            Point(int val, int x, int y) : val(val), x(x), y(y) {
            }
            bool operator<(const Point& other) const {
                return this->val > other.val;
            }
        };
        priority_queue<Point> pq;
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
        for (int i = 0; i < (int)matrix.size(); i++) {
            pq.emplace(matrix[i][0], i, 0);
        }
        while (--k) {
            Point point = pq.top();
            pq.pop();
            if (point.y + 1 < (int)matrix[0].size()) {
                pq.emplace(matrix[point.x][point.y + 1], point.x, point.y + 1);
            }
        }
        return pq.top().val;
    }
};
// @lc code=end
