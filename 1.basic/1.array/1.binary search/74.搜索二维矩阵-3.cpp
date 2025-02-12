/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 15:49:39
 * 	 modified: 	2025-02-11 15:56:35
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto r = upper_bound(matrix.begin(), matrix.end(), target, [](int e, vector<int>& v) {
            // auto = vector<vector<int>>::iterator
            return v[0] > e;
        });
        if (r-- == matrix.begin()) return false;
        return binary_search(r->begin(), r->end(), target);
    }
};
// @lc code=end
