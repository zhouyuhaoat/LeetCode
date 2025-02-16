/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-15 21:33:18
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
        // two count -> counteract each other -> one count
        vector<int> cnt(128); // have, need => need - have <=> (-have) + (+need)
        for (char c : t) {
            cnt[c]++;
        }
        int want = cnt.size() - ranges::count(cnt, 0);
        // have >= need => non-positive => cover
        // have < need => positive => un-cover
        // want: count of positive elements in cnt
        // cover: have >= need => want = 0
        auto update = [&](int c, int add) {
            if (cnt[c] == 1 && add == -1) { // positive -> non-positive
                want--;
            } else if (cnt[c] == 0 && add == 1) { // non-positive -> positive
                want++;
            }
            cnt[c] += add;
        };
        int res = -1, len = INT_MAX;
        for (int lo = 0, hi = 0; lo < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && want > 0) {
                update(s[hi++], -1);
            }
            if (want == 0 && len > hi - lo) {
                len = hi - lo;
                res = lo;
            }
            update(s[lo], 1);
        }
        return len == INT_MAX ? string() : s.substr(res, len);
    }
};
// @lc code=end
