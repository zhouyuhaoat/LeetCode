/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 12:38:55
 *   modified:  2025-03-02 13:04:10
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
    // q_max prioritized over q_min
    // q_min < median <= q_max
    // 0 <= q_max.size() - q_min.size() <= 1

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // balance: maintain the size of two heaps
        if (q_max.empty() || num >= q_max.top()) {
            q_max.emplace(num);
            if (q_max.size() - q_min.size() > 1) {
                q_min.emplace(q_max.top());
                q_max.pop();
            }
        } else {
            q_min.emplace(num);
            if (q_min.size() > q_max.size()) {
                q_max.emplace(q_min.top());
                q_min.pop();
            }
        }
    }

    double findMedian() {
        if (q_max.size() > q_min.size()) {
            return q_max.top();
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
