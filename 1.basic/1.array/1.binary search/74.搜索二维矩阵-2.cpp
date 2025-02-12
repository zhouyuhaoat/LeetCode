/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 15:46:47
 * 	 modified: 	2025-02-11 15:49:10
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
    int upper_bound(vector<vector<int>>& A, int e) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi][0] > e) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = upper_bound(matrix, target);
        if (r-- == 0) return false; // valid row
        return ranges::binary_search(matrix[r], target);
    }
};
// @lc code=end
