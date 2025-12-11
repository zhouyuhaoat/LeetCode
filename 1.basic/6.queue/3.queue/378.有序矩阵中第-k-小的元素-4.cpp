/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:03:16
 *   modified:  2025-03-03 09:27:55
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
    int count(vector<vector<int>>& A, int e) {
        int cnt = 0;
        for (auto& row : A) {
            cnt += distance(row.begin(), ranges::upper_bound(row, e)); // less than or equal to val
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = matrix[0][0], hi = matrix[m - 1][n - 1] + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (count(matrix, mi) >= k) { // count of elements <= mi
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
