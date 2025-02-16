/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-16 09:36:21
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
        unordered_map<char, int> win, tar;
        for (char c : t) {
            tar[c]++;
        }
        int res = -1, len = INT_MAX, cnt = 0;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            if (win[s[hi]]++ < tar[s[hi]]) {
                cnt++;
            }
            while (cnt == (int)t.size()) {
                if (len > hi - lo + 1) {
                    len = hi - lo + 1;
                    res = lo;
                }
                if (--win[s[lo]] < tar[s[lo]]) {
                    cnt--;
                }
                lo++;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
