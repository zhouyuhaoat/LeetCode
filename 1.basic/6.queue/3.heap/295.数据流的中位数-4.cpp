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
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    // left < median <= right

public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (right.empty() || num >= right.top()) {
            right.emplace(num);
            if (right.size() - left.size() > 1) {
                left.emplace(right.top());
                right.pop();
            }
        } else {
            left.emplace(num);
            if (right.size() < left.size()) {
                right.emplace(left.top());
                left.pop();
            }
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return right.top();
    }
};
// @lc code=end
