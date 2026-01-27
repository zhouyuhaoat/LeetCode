/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:40:17
 *   modified:  2025-12-27 18:20:47
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
        unordered_map<int, int> cnt;
        for (int lo = 0, hi = 0; hi < (int)fruits.size(); hi++) { // [lo, hi]
            cnt[fruits[hi]]++;
            while ((int)cnt.size() > k) {
                if (--cnt[fruits[lo]] == 0) {
                    cnt.erase(fruits[lo]);
                }
                lo++;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
// @lc code=end
