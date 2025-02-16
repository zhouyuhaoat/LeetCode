/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-16 18:38:48
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        // each value at most k: lo - k, ..., lo - 1
        int lo = 1; // write
        // [0, lo): unique; [lo, hi): duplicate; [hi, inf): unknown
        for (int hi = 1; hi < (int)nums.size(); hi++) { // read
            if (nums[hi] != nums[lo - 1]) { // k = 1 -> unique
                nums[lo++] = nums[hi]; // move forward, overwrite duplicate
            } // skip duplicate
        }
        return lo; // [0, lo) => lo = size
    }
};
// @lc code=end
