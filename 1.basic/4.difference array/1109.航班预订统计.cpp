/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:05
 *   modified:  2025-02-28 15:24:28
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
        for (int i = 1; i < (int)nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    void update(int left, int right, int val) { // [left, right]
        diff[left] += val;
        if (right + 1 < (int)diff.size()) {
            diff[right + 1] -= val;
        }
    }

    vector<int> getResult() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < (int)diff.size(); i++) {
            res[i] = res[i - 1] + diff[i]; // prefix or cumulative sum
        }
        return res;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n, 0);
        Difference diff(nums);
        for (auto& booking : bookings) {
            int first = booking[0] - 1, last = booking[1] - 1, val = booking[2];
            diff.update(first, last, val);
        }
        return diff.getResult();
    }
};
// @lc code=end
