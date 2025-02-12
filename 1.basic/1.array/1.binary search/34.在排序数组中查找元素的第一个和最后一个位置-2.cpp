/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-01-20 22:16:41
 * 	 modified: 	2025-01-20 22:24:40
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = distance(nums.begin(), ranges::lower_bound(nums, target));
        int last = distance(nums.begin(), ranges::upper_bound(nums, target)) - 1;
        return first <= last ? vector<int>{first, last} : vector<int>{-1, -1};
    }
};
// @lc code=end
