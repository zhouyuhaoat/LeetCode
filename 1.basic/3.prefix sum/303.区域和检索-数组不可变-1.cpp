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
public:
    vector<int> pre;

    NumArray(vector<int>& nums) {
        pre.resize(nums.size() + 1);
        for (int i = 1; i <= (int)nums.size(); i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
            /*
                prefix or cumulative sum
                - pre[i] = sum[0, i)
                    - pre[i] = pre[i - 1] + nums[i - 1]
                    - nums[i - 1] = pre[i] - pre[i - 1]
                - sum[left, right) = sum[0, right) - sum[0, left)
                    - sum[left, right) = pre[right] - pre[left]
                - prefix: not include itself, all previous
            */
        }
    }

    int sumRange(int left, int right) { // sum[left, right] = sum[0, right + 1)
        return pre[right + 1] - pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
