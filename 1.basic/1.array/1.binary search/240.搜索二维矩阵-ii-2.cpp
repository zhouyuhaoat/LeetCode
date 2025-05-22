/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 16:07:15
 *   modified:  2025-05-22 13:41:43
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool zigzag_search(vector<vector<int>>& A, int e) {
        int m = A.size(), n = A[0].size();
        int i = m - 1, j = 0; // bottom-left corner
        while (i >= 0 && j < n) {
            if (A[i][j] > e) {
                i--;
            } else if (A[i][j] < e) {
                j++;
            } else {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return zigzag_search(matrix, target);
    }
};
// @lc code=end
