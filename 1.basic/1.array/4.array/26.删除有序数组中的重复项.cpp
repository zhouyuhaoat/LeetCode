/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 14:53:14
 * 	 modified: 	2024-10-26 15:05:58
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // each value at most k: k = 1
        // each value only one: unique
        int lo = 1;
        for (int hi = 1; hi < (int)nums.size(); hi++) {
            if (nums[hi] != nums[lo - 1]) {
                nums[lo++] = nums[hi];
            }
        }
        return lo; // size
    }
};
// @lc code=end
