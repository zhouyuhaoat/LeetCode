/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:40:17
 *   modified:  2026-01-27 21:26:11
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        pair<int, int> cnt1, cnt2; // {type, count}
        auto isFit = [&](int fruit, int delta) { // fit in baskets
            if (fruits[fruit] == cnt1.first) {
                cnt1.second += delta;
            } else if (fruits[fruit] == cnt2.first) {
                cnt2.second += delta;
            } else {
                return false; // new type
            }
            return true; // existing type
        };
        for (int lo = 0, hi = 0; hi < (int)fruits.size(); hi++) { // [lo, hi]
            if (!isFit(hi, 1)) {
                while (cnt1.second > 0 && cnt2.second > 0) {
                    isFit(lo++, -1);
                }
                (cnt1.second == 0 ? cnt1 : cnt2) = {fruits[hi], 1};
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
// @lc code=end
