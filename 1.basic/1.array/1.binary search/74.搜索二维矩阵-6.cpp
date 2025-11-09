/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 16:01:29
 *   modified:  2025-05-22 13:41:29
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
private:
    bool zigzag_search(vector<vector<int>>& A, int e) {
        int m = A.size(), n = A[0].size();
        int i = 0, j = n - 1; // top-right corner
        while (i < m && j >= 0) {
            if (A[i][j] > e) {
                j--;
            } else if (A[i][j] < e) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return zigzag_search(matrix, target);
    }
};
// @lc code=end
