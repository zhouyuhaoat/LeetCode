/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 15:38:59
 * 	 modified: 	2024-10-26 15:41:24
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lo = 0;
        for (int hi = 0; hi < (int)nums.size(); hi++) {
            if (nums[hi] != 0) {
                swap(nums[lo++], nums[hi]);
            }
        }
    }
};
// @lc code=end
