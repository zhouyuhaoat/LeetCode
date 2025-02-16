/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-16 18:51:09
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // each value at most k: lo - k, ..., lo - 1
        // if val == lo - k, val == lo - k == ... == lo - 1 since sorted
        // then there are k + 1 duplicates, so valid if val != lo - k
        if (nums.size() <= 2) return nums.size();
        int lo = 2;
        // [0, lo): valid; [lo, hi): invalid; [hi, inf): unknown
        for (int hi = 2; hi < (int)nums.size(); hi++) {
            if (nums[hi] != nums[lo - 2]) {
                nums[lo++] = nums[hi];
            }
        }
        return lo;
    }
};
// @lc code=end
