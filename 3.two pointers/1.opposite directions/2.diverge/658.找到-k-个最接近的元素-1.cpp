/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 15:38:34
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        ranges::sort(arr, [&](int a, int b) {
            return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
        });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>{arr.begin(), arr.begin() + k};
    }
};
// @lc code=end
