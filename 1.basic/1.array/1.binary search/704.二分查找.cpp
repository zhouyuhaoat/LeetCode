/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 10:19:20
 * 	 modified: 	2024-10-24 10:22:07
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int binSearch(vector<int>& A, int e) {
        int lo = 0, hi = A.size();
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (A[mi] > e) {
                hi = mi;
            } else if (A[mi] < e) {
                lo = mi + 1;
            } else {
                return mi;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binSearch(nums, target);
    }
};
// @lc code=end
