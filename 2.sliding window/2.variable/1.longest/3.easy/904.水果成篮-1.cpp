/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:40:17
 *   modified:  2025-12-27 18:19:44
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
        int res = 0, k = 2;
        unordered_map<int, int> cnt; // freq
        for (int lo = 0, hi = 0; hi < (int)fruits.size(); lo++) { // [lo, hi)
            while (hi < (int)fruits.size() && (int)cnt.size() <= k) {
                cnt[fruits[hi++]]++;
            }
            res = max(res, (int)cnt.size() <= k ? hi - lo : hi - lo - 1);
            if (--cnt[fruits[lo]] == 0) {
                cnt.erase(fruits[lo]);
            }
        }
        return res;
    }
};
// @lc code=end
