/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-21 21:57:07
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
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < (int)nums.size(); i++) {
            int lo = i - k + 1;
            while (!q.empty() && q.front() < lo) { // ensure within the window
                q.pop_front();
            }
            while (!q.empty() && nums[i] >= nums[q.back()]) { // maintain descending order
                q.pop_back();
            }
            q.emplace_back(i);
            if (lo >= 0) {
                res.emplace_back(nums[q.front()]);
            }
        }
        return res;
    }
};
// @lc code=end
