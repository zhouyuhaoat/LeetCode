/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 15:49:39
 *   modified:  2025-05-22 13:38:34
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
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](int val, vector<int>& vec) { // first > val
            return val < vec[0];
        });
        if (row-- == matrix.begin()) return false;
        return binary_search(row->begin(), row->end(), target);
        // vector<vector<int>>::iterator => vector<int> = [it->begin(), it->end())
    }
};
// @lc code=end
