/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:05
 *   modified:  2026-01-28 22:42:25
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Difference {
private:
    vector<int> diff;

public:
    Difference(vector<int>& nums) {
        diff.resize(nums.size());
        diff[0] = nums[0];
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            diff[i + 1] = nums[i + 1] - nums[i];
        }
    }

    void update(int lo, int hi, int val) { // [lo, hi)
        diff[lo] += val;
        if (hi < (int)diff.size()) {
            diff[hi] -= val;
        }
    }

    vector<int> getOriginal() {
        vector<int> orig(diff.size()); // prefix sum
        orig[0] = diff[0];
        for (int i = 0; i < (int)diff.size() - 1; i++) {
            orig[i + 1] = orig[i] + diff[i + 1];
        }
        return orig;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        Difference diff(nums);
        for (auto& booking : bookings) {
            int first = booking[0] - 1, last = booking[1], val = booking[2];
            diff.update(first, last, val);
        }
        return diff.getOriginal();
    }
};
// @lc code=end
