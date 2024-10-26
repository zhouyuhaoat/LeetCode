/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 13:43:31
 * 	 modified: 	2024-10-26 14:20:34
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
        deque<int> q; // only store the index, since monotonic value
        for (int i = 0; i < (int)nums.size(); i++) {
            // if left < right, left can be discarded
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                // monotonic queue: decrease
                q.pop_back();
            }
            q.emplace_back(i);
            if (i >= k - 1) {
                res.emplace_back(nums[q.front()]);
                while (!q.empty() && q.front() <= i - k + 1) {
                    q.pop_front(); // deque: double-ended queue
                }
            }
        }
        return res;
    }
};
// @lc code=end
