/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-20 18:17:43
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
        multiset<int> win;
        for (int i = 0; i < (int)nums.size(); i++) {
            win.emplace(nums[i]);
            int lo = i - k + 1; // the left bound of the window
            if (lo >= 0) {
                res.emplace_back(*win.rbegin());
                win.erase(win.find(nums[lo]));
            }
        }
        return res;
    }
};
// @lc code=end
