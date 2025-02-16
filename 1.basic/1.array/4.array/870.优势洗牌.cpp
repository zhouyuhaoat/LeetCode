/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 22:48:12
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        ranges::sort(nums1);
        vector<int> id(n); // value -> index
        ranges::iota(id, 0);
        ranges::sort(id, [&](int a, int b) {
            return nums2[a] < nums2[b];
        });
        vector<int> res(n);
        // greedy: 田忌赛马
        int lo = 0, hi = n - 1; // 彼下驷与彼上驷
        for (int x : nums1) {
            if (x > nums2[id[lo]]) {
                res[id[lo++]] = x;
            } else {
                res[id[hi--]] = x; // 君下驷与彼上驷
            }
        }
        return res;
    }
};
// @lc code=end
