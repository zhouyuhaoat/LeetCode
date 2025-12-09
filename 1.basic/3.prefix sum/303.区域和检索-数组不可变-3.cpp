/*
 *   author:    zhouyuhao
 *   created:   2025-12-02 15:07:29
 *   modified:  2025-12-02 15:53:29
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
private:
    vector<int> sum; // partial sum

public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), sum.begin() + 1);
    }

    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};
// @lc code=end
