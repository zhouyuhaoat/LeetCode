/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-21 21:55:17
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        /*
            if left <= right, left can be discarded
            => left > right => descending monotonic stack
            + sliding window => descending monotonic deque
            => double-ended queue
        */
        vector<int> res;
        deque<int> q; // index -> value
        for (int i = 0; i < (int)nums.size(); i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
            int lo = i - k + 1;
            if (lo >= 0) {
                res.emplace_back(nums[q.front()]);
                // while -> if: each time only one element is out of the left bound
                if (q.front() <= lo) {
                    q.pop_front();
                }
            }
        }
        return res;
    }
};
// @lc code=end
