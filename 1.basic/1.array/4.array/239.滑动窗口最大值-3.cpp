/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 23:01:18
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
        deque<int> q; // only store the index, since monotonic value
        for (int i = 0; i < (int)nums.size(); i++) {
            // if left < right, left can be discarded
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                // maintain the (descending) monotonic queue
                q.pop_back();
            }
            q.emplace_back(i);
            if (i >= k - 1) {
                res.emplace_back(nums[q.front()]);
                if (q.front() <= i - k + 1) {
                    q.pop_front(); // deque: double-ended queue
                }
            }
        }
        return res;
    }
};
// @lc code=end
