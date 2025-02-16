/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-15 21:33:24
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        for (char c : t) {
            cnt[c]++;
        }
        int want = cnt.size() - ranges::count(cnt, 0);
        auto update = [&](int c, int add) {
            if (cnt[c] == 1 && add == -1) {
                want--;
            } else if (cnt[c] == 0 && add == 1) {
                want++;
            }
            cnt[c] += add;
        };
        int res = -1, len = INT_MAX;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            update(s[hi], -1);
            while (want == 0) {
                if (len > hi - lo + 1) {
                    len = hi - lo + 1;
                    res = lo;
                }
                update(s[lo++], 1);
            }
        }
        return len == INT_MAX ? string() : s.substr(res, len);
    }
};
// @lc code=end
