/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 22:53:03
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
                w.erase(w.find(nums[i - k + 1]));
                // remove the left bound brutely
            }
        }
        return res;
    }
};
// @lc code=end
