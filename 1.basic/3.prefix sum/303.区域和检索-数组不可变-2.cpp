/*
 *   author:    zhouyuhao
 *   created:   2025-02-28 15:07:29
 *   modified:  2025-02-28 15:53:29
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> acc; // accumulated sum

    NumArray(vector<int>& nums) {
        acc.emplace_back(0);
        for (int num : nums) {
            acc.emplace_back(acc.back() + num);
        }
    }

    int sumRange(int left, int right) {
        return acc[right + 1] - acc[left];
    }
};
// @lc code=end
