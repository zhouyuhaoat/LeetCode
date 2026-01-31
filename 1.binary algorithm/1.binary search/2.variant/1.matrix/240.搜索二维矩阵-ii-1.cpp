/*
 *   author:    zhouyuhao
 *   created:   2025-05-21 20:50:51
 *   modified:  2026-01-31 16:30:07
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
        return ranges::any_of(matrix, [&](auto& row) {
            return ranges::find(row, target) != row.end();
        });
    }
};
// @lc code=end
