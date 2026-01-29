/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:13:57
 *   modified:  2025-03-02 10:52:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        pq.push(val);
        if ((int)pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};
// @lc code=end
