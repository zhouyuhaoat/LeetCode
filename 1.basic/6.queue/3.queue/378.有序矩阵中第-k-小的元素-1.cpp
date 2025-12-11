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
private:
    struct Point {
        int val, x, y;
        Point(int val, int x, int y) : val(val), x(x), y(y) {
        }
        bool operator<(const Point& other) const {
            return this->val > other.val;
        }
    };
    priority_queue<Point> pq;

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) { // multi-way merge
            pq.emplace(matrix[i][0], i, 0);
        }
        while (--k) {
            Point point = pq.top();
            pq.pop();
            if (point.y + 1 < n) {
                pq.emplace(matrix[point.x][point.y + 1], point.x, point.y + 1);
            }
        }
        return pq.top().val;
    }
};
// @lc code=end
