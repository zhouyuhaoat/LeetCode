/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 09:33:56
 * 	 modified: 	2024-11-03 10:02:42
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> pre; // prefix sum, cumulative sum

    NumArray(vector<int>& nums) {
        pre.resize(nums.size() + 1);
        for (int i = 0; i < (int)nums.size(); i++) {
            pre[i + 1] = pre[i] + nums[i];
            // pre[i] = sum[0, i) = sum[0, i - 1]
            // prefix: not include itself, all previous
        }
    }

    int sumRange(int left, int right) {
        return pre[right + 1] - pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
