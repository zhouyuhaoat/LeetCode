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
            left.push(num);
            right.push(left.top());
            left.pop();
        } else {
            right.push(num);
            left.push(right.top());
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
// @lc code=end
