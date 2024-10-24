/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 10:01:47
 * 	 modified: 	2024-10-24 10:13:06
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int upper_bound(vector<int>& A, int e) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (A[mi] > e) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = upper_bound(nums, target - 1);
        int last = upper_bound(nums, target) - 1;
        if (first < (int)nums.size() && nums[first] == target) {
            return {first, last};
        } else {
            return {-1, -1};
        }
    }
};
// @lc code=end
