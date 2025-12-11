/*
 *   author:    zhouyuhao
 *   created:   2024-12-15 15:48:45
 *   modified:  2025-03-02 13:01:53
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
    priority_queue<int> left; // left < median <= right
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
    }

    void addNum(int num) { // filter
        if (right.size() == left.size()) {
            left.emplace(num);
            right.emplace(left.top());
            left.pop();
        } else {
            right.emplace(num);
            left.emplace(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (right.size() == left.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
