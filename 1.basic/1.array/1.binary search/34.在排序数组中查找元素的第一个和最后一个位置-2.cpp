/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 10:01:47
 * 	 modified: 	2024-10-24 10:16:22
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
    int lower_bound(vector<int>& A, int e) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (A[mi] >= e) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = lower_bound(nums, target + 1) - 1;
        if (first < (int)nums.size() && nums[first] == target) {
            return {first, last};
        } else {
            return {-1, -1};
        }
    }
};
// @lc code=end
