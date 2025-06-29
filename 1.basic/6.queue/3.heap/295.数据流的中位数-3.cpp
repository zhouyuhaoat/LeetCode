/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:14:03
 *   modified:  2025-03-02 13:03:09
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
    // left <= median < right

public:
    MedianFinder() {
    }

    void addNum(int num) { // balance: maintain the size of two heaps
        if (left.empty() || num <= left.top()) {
            left.emplace(num);
            if (left.size() - right.size() > 1) {
                right.emplace(left.top());
                left.pop();
            }
        } else {
            right.emplace(num);
            if (left.size() < right.size()) {
                left.emplace(right.top());
                right.pop();
            }
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
};
// @lc code=end
