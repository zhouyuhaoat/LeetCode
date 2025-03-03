/*
 *   author:    zhouyuhao
 *   created:   2024-12-15 15:48:45
 *   modified:  2025-03-02 23:43:02
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
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder() : left(nums.end()), right(nums.end()) {
    }

    void addNum(int num) {
        size_t n = nums.size();
        nums.emplace(num);
        if (n == 0) { // empty
            // before: left == right == nullptr
            // after: left == right -> the only element
            left = right = nums.begin();
        } else if (n & 1) { // odd
            // before: left == right -> median
            // if num < *left: num, ..., left == right
            // if num >= *left: left == right, ..., num
            num < *left ? left-- : right++;
        } else { // even
            // before: left_median <- left, right -> right_median
            if (num > *left && num < *right) {
                // left, num, right
                left++, right--;
            } else if (num <= *left) {
                // if num < *left: num, ..., left, right
                // if num == *left: left, num, right
                right--, left = right;
            } else {
                // if num >= *right: left, right, ..., num
                left++;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
