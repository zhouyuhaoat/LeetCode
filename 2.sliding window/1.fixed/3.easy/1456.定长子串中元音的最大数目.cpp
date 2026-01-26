/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 19:35:35
 *   modified:  2025-12-25 19:55:37
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, cnt = 0;
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        for (int hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            cnt += isVowel(s[hi]);
            int lo = hi - k + 1;
            if (lo >= 0) {
                res = max(res, cnt);
                cnt -= isVowel(s[lo]);
            }
        }
        return res;
    }
};
// @lc code=end
