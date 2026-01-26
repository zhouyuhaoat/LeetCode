/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:51:32
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128);
        for (char ch : t) {
            cnt[ch]++;
        }
        /*
            two count -> counteract each other -> one count
            - count = need - have = (-have) + (+need)
            - cover a char: have < need => count > 0
         */
        int res = -1, len = INT_MAX, cover = 0;
        for (int lo = 0, hi = 0; lo < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && cover < (int)t.size()) {
                if (cnt[s[hi++]]-- > 0) {
                    cover++;
                }
            }
            if (cover == (int)t.size() && hi - lo < len) {
                len = hi - lo;
                res = lo;
            }
            if (++cnt[s[lo]] > 0) {
                cover--;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
