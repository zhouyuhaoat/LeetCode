/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:10
 *   modified:  2025-02-28 15:12:42
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
    vector<int> pref; // prefix sum

public:
    NumArray(vector<int>& nums) {
        pref.resize(nums.size() + 1);
        for (int i = 0; i < (int)nums.size(); i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
    }

    int sumRange(int left, int right) { // [left, right + 1)
        return pref[right + 1] - pref[left];
    }
};
// @lc code=end
