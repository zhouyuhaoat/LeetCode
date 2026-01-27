/*
 *   author:    zhouyuhao
 *   created:   2025-12-28 19:02:34
 *   modified:  2026-01-27 22:37:47
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
    int getPrefix(vector<int>& nums, int& sum, int x) {
        int lo = 0;
        while (lo < (int)nums.size() && sum + nums[lo] <= x) {
            sum += nums[lo++];
        }
        return lo;
    }

    void leftRotate(vector<int>& nums, int& lo, int& hi, int& sum, int x) {
        sum += nums[--hi];
        while (lo > 0 && sum > x) {
            sum -= nums[--lo];
        }
    }

public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();

        int lo = getPrefix(nums, sum, x); // prefix: [0, lo)
        if (lo == n && sum < x) return -1;
        int res = sum == x ? lo : INT_MAX;

        int hi = n; // suffix: [hi, size)
        while (hi > 0) {
            leftRotate(nums, lo, hi, sum, x);
            if (sum > x) break;
            if (sum == x) res = min(res, lo + (n - hi));
        }

        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
