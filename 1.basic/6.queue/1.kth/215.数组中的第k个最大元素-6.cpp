/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 15:55:30
 *   modified:  2025-03-02 15:59:56
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - k; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
// @lc code=end
