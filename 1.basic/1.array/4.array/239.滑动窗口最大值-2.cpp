/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 23:00:49
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
        priority_queue<pair<int, int>> q; // max-heap: (value, index)
        // index use to check out of the left bound
        for (int i = 0; i < (int)nums.size(); i++) {
            q.emplace(nums[i], i);
            if (i >= k - 1) {
                res.emplace_back(q.top().first);
                while (!q.empty() && q.top().second <= i - k + 1) {
                    // maintain the queue (size)
                    // possibly multiple elements out of the left bound
                    // just not on the top and not pop out before
                    q.pop();
                }
            }
        }
        return res;
    }
};
// @lc code=end
