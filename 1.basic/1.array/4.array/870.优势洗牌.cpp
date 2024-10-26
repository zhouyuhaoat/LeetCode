/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:25:00
 * 	 modified: 	2024-10-26 16:45:37
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int a, int b) {
            return nums2[a] < nums2[b];
        });
        sort(nums1.begin(), nums1.end());
        vector<int> res(n);
        int lo = 0, hi = n - 1;
        for (int x : nums1) { // 田忌赛马
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
