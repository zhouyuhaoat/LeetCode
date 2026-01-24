/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 15:59:36
 *   modified:  2025-05-22 13:39:26
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
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = ranges::upper_bound(matrix, target, {}, [](vector<int>& vec) { // compare -> project
            return vec[0];
        });
        if (row-- == matrix.begin()) return false;
        return ranges::binary_search(*row, target);
    }
};
// @lc code=end
