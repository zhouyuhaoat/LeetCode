/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 15:34:59
 * 	 modified: 	2024-10-26 15:38:16
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int hi = nums.size(); // lo: read index; hi: write index
        // reverse to avoid redundant assignments, but un-sorted
        for (int lo = 0; lo < hi; lo++) {
            if (nums[lo] == val) {
                nums[lo--] = nums[--hi];
            }
        }
        return hi;
    }
};
// @lc code=end
