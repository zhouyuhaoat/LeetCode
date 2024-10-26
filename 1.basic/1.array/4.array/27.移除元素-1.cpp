/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 15:06:18
 * 	 modified: 	2024-10-26 15:11:19
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
        int lo = 0; // write
        for (int hi = 0; hi < (int)nums.size(); hi++) { // read
            if (nums[hi] != val) {
                nums[lo++] = nums[hi];
            }
        }
        return lo; // size
    }
};
// @lc code=end
