/*
 *   author:    zhouyuhao
 *   created:   2025-12-28 19:02:34
 *   modified:  2026-01-27 22:41:11
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
private:
    int getSuffix(vector<int>& nums, int& sum, int x) {
        int hi = nums.size();
        while (hi > 0 && sum + nums[hi - 1] <= x) {
            sum += nums[--hi];
        }
        return hi;
    }

    void rightRotate(vector<int>& nums, int& lo, int& hi, int& sum, int x) {
        sum += nums[lo++];
        while (hi < (int)nums.size() && sum > x) {
            sum -= nums[hi++];
        }
    }

public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();

        int hi = getSuffix(nums, sum, x); // suffix: [hi, size)
        if (hi == 0 && sum < x) return -1;
        int res = sum == x ? n - hi : INT_MAX;

        int lo = 0; // prefix: [0, lo)
        while (lo < n) {
            rightRotate(nums, lo, hi, sum, x);
            if (sum > x) break;
            if (sum == x) res = min(res, lo + (n - hi));
        }

        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
