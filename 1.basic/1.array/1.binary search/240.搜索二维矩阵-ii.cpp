/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 18:40:09
 * 	 modified: 	2024-10-24 18:48:01
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1; // zig-zag search: top-right -> bottom-left, O(m + n)
        while (i < m && 0 <= j) {
            if (target < matrix[i][j]) {
                j--; // right -> left: decrease
            } else if (matrix[i][j] < target) {
                i++; // top -> bottom: increase
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
