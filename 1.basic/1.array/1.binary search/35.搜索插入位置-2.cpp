/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 10:26:04
 * 	 modified: 	2024-10-24 10:36:50
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
        int id = upper_bound(nums.begin(), nums.end(), target) - nums.begin(); // stability
        if (id != 0 && nums[id - 1] == target) {
            return id - 1;
        } else {
            return id;
        }
    }
};
// @lc code=end
