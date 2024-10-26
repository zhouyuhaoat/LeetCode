/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:12:02
 * 	 modified: 	2024-10-26 16:13:12
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) { // circular shift
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = (i * n + j + k) % (m * n);
                res[id / n][id % n] = grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
