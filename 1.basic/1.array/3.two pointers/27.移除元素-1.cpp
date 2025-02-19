/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-19 11:40:13
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        int lo = 0;
        // [0, lo): != val; [lo, hi): == val; [hi, inf): unknown
        for (int hi = 0; hi < (int)nums.size(); hi++) {
            if (nums[hi] != val) {
                nums[lo++] = nums[hi];
                // just move forward, overwrite, no need to swap
                // if swap, [lo, hi) must all be equal to val
            }
        }
        return lo;
    }
};
// @lc code=end
