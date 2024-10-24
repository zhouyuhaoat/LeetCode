/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 20:17:37
 * 	 modified: 	2024-10-24 20:43:51
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
        auto r = upper_bound(matrix.begin(), matrix.end(), target, [](int a, vector<int>& b) {
            return b[0] > a;
        });
        if (r-- == matrix.begin()) return false;
        return binary_search(r->begin(), r->end(), target);
    }
};
// @lc code=end
