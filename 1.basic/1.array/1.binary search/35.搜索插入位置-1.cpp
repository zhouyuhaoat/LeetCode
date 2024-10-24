/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 10:23:09
 * 	 modified: 	2024-10-24 10:25:46
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
// @lc code=end
