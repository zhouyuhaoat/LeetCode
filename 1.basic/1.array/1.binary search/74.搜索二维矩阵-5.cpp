/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 15:59:36
 * 	 modified: 	2025-02-11 16:00:07
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
        auto r = ranges::upper_bound(matrix, target, {}, [](vector<int>& v) {
            return v[0];
        });
        if (r-- == matrix.begin()) return false;
        return ranges::binary_search(*r, target); // dereference
    }
};
// @lc code=end
