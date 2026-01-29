/*
 *   author:    zhouyuhao
 *   created:   2024-12-15 14:10:14
 *   modified:  2025-03-01 20:28:42
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
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
            if ((int)pq.size() > (int)nums.size() - k + 1) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
// @lc code=end
