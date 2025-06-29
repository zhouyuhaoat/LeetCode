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
        /*
            median by multiset and iterators left, right
            1. empty
                - before: left == right == nullptr
                - after: left == right -> the only element
            2. odd
                - before: left == right -> median
                - if num < *left: num, ..., left == right
                - if num >= *left: left == right, (...,) num
            3. even
                - before: left median <- left, right -> right median
                - if *left < num < *right: left, num, right
                - if num <= *left
                    - if num < *left: num, ..., left, right
                    - if num == *left: left, num, right
                - if num >= *right: left, right, (...,) num
        */
        if (n == 0) {
            left = right = nums.begin();
        } else if (n & 1) {
            num < *left ? left-- : right++;
        } else {
            if (num > *left && num < *right) {
                left++, right--;
            } else if (num <= *left) {
                right--, left = right;
            } else {
                left++;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};
// @lc code=end
