/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 09:52:02
 * 	 modified: 	2025-02-19 10:47:45
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
        int hi = nums.size();
        // [0, lo): != val; [lo, hi): unknown; [hi, inf): == val
        // reverse: avoid redundant assignments, but un-stable
        for (int lo = 0; lo < hi; lo++) {
            if (nums[lo] == val) {
                nums[lo--] = nums[--hi]; // swap(begin, end) -> unstable
            }
        }
        return hi;
    }
};
// @lc code=end
