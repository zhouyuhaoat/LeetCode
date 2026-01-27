/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:33:47
 *   modified:  2025-12-27 23:37:21
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, cost = 0;
        for (int lo = 0, hi = 0; hi < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && cost <= maxCost) {
                cost += abs(s[hi] - t[hi]);
                hi++;
            }
            res = max(res, cost <= maxCost ? hi - lo : hi - lo - 1);
            cost -= abs(s[lo] - t[lo]);
        }
        return res;
    }
};
// @lc code=end
