/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 15:55:08
 * 	 modified: 	2025-02-11 15:58:13
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
        auto r = lower_bound(matrix.begin(), matrix.end(), target, [](vector<int>& v, int e) {
            return v[0] <= e;
        });
        if (r-- == matrix.begin()) return false;
        return binary_search(r->begin(), r->end(), target);
    }
};
// @lc code=end
