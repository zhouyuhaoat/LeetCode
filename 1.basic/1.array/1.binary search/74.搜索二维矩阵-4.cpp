/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 15:55:08
 *   modified:  2025-05-22 13:30:43
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
        auto row = lower_bound(matrix.begin(), matrix.end(), target, [](vector<int>& vec, int val) { // first !< val
            return vec[0] <= val; // !(vec[0] <= val) => val < vec[0]
        });
        if (row-- == matrix.begin()) return false;
        return binary_search(row->begin(), row->end(), target);
    }
};
// @lc code=end
