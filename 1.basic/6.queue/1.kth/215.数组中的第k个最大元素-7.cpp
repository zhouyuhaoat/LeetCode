/*
 *   author:    zhouyuhao
 *   created:   2024-12-11 22:09:03
 *   modified:  2025-03-01 20:28:29
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
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.emplace(num);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
// @lc code=end
