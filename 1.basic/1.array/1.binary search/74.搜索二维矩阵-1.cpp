/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 15:43:19
 * 	 modified: 	2025-02-11 15:45:30
 * 	 project: 	LeetCode of labuladong
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
    bool binary_search(vector<vector<int>>& A, int e) {
        int m = A.size(), n = A[0].size();
        int lo = 0, hi = m * n;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            int tmp = A[mi / n][mi % n];
            if (tmp > e) {
                hi = mi;
            } else if (tmp < e) {
                lo = mi + 1;
            } else {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binary_search(matrix, target);
    }
};
// @lc code=end
