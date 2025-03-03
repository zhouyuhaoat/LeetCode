/*
 *   author:    zhouyuhao
 *   created:   2024-12-15 15:55:55
 *   modified:  2025-03-02 13:01:38
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
private:
    priority_queue<int> q_min;
    priority_queue<int, vector<int>, greater<int>> q_max;
    // as possible as balance the size of two heaps
    // q_min prioritized over q_max
    // q_min <= median < q_max
    // 0 <= q_min.size() - q_max.size() <= 1

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // filtration: ensure valid (max/min) input
        if (q_min.size() == q_max.size()) {
            q_max.emplace(num);
            q_min.emplace(q_max.top());
            q_max.pop();
        } else {
            q_min.emplace(num);
            q_max.emplace(q_min.top());
            q_min.pop();
        }
    }

    double findMedian() {
        if (q_min.size() > q_max.size()) {
            return q_min.top();
        }
        return (q_min.top() + q_max.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
