/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 18:55:08
 * 	 modified: 	2024-10-24 19:29:31
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m * n; // matrix -> array
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            int e = matrix[mi / n][mi % n];
            if (target < e) {
                hi = mi;
            } else if (e < target) {
                lo = mi + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
