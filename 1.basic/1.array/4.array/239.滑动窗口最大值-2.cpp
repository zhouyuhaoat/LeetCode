/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-21 21:46:43
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
        priority_queue<pair<int, int>> q; // max-heap: {value, index}
        /*
            fixed-size sliding window
            - max-heap => maximum value
            - fixed size => use index to bound check
            - value -> index: use pair to bind index with value
        */
        for (int i = 0; i < (int)nums.size(); i++) {
            q.emplace(nums[i], i);
            int lo = i - k + 1;
            if (lo >= 0) {
                res.emplace_back(q.top().first);
                while (!q.empty() && q.top().second <= lo) {
                    q.pop();
                }
                /*
                    if -> while
                    - possibly multiple elements out of the left bound
                    - just not on the top and not pop out before
                */
            }
        }
        return res;
    }
};
// @lc code=end
