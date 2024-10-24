/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 19:28:24
 * 	 modified: 	2024-10-24 20:16:56
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
    int upper_bound(vector<vector<int>>& A, int e) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (e < A[mi][0]) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = upper_bound(matrix, target);
        if (r != 0) r--;
        return binary_search(matrix[r].begin(), matrix[r].end(), target);
    }
};
// @lc code=end
