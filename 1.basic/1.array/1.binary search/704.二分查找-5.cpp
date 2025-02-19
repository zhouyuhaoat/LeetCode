/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-01-27 20:43:32
 * 	 modified: 	2025-01-27 20:47:41
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	501, Shangrao
 */

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int id = distance(nums.begin(), lower_bound(nums.begin(), nums.end() - 1, target));
        return nums[id] == target ? id : -1;
    }
};
// @lc code=end
