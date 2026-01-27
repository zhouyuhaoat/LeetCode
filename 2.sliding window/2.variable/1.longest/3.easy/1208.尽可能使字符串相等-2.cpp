/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:33:47
 *   modified:  2025-12-27 16:35:15
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
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            cost += abs(s[hi] - t[hi]);
            while (cost > maxCost) {
                cost -= abs(s[lo] - t[lo]);
                lo++;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
// @lc code=end
