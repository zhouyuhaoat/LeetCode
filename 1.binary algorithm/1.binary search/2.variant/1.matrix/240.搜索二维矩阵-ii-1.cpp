/*
 *   author:    zhouyuhao
 *   created:   2025-05-21 20:50:51
 *   modified:  2026-01-23 13:51:57
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            if (ranges::find(row, target) != row.end()) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
