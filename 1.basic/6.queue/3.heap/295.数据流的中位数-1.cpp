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
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    /*
        left <= median < right
        - left prioritized over right
        - 0 <= left.size() - right.size() <= 1
        - as possible as balance the size of two heaps
    */

public:
    MedianFinder() {
    }

    void addNum(int num) { // filtration
        if (left.size() == right.size()) {
            right.emplace(num);
            left.emplace(right.top());
            right.pop();
        } else {
            left.emplace(num);
            right.emplace(left.top());
            left.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
