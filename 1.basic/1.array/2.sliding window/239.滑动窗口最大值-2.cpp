/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 13:43:31
 * 	 modified: 	2024-10-26 14:17:17
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
        priority_queue<pair<int, int>> q; // max-heap: (value, index)
        // index use to check out of the left bound
        for (int i = 0; i < (int)nums.size(); i++) {
            q.emplace(nums[i], i);
            if (i >= k - 1) {
                res.emplace_back(q.top().first);
                while (!q.empty() && q.top().second <= i - k + 1) {
                    // while, not if, out of the left bound of the window
                    q.pop();
                }
            }
        }
        return res;
    }
};
// @lc code=end
