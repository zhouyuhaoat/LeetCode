/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 13:43:31
 * 	 modified: 	2024-10-26 13:48:09
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> w;
        for (int i = 0; i < (int)nums.size(); i++) {
            w.emplace(nums[i]);
            if (i >= k - 1) {
                res.emplace_back(*w.rbegin());
                w.erase(w.find(nums[i - k + 1])); // not w.erase(nums[i - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end
