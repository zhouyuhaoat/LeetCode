/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-15 21:31:18
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
        // cover a char: have < need, before in, after out
        // cnt: monitor the number of covered chars
        // cover: have >= need => cnt == size
        // cnt can not be bigger than the size
        for (int lo = 0, hi = 0; lo < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && cnt < (int)t.size()) {
                if (win[s[hi]]++ < tar[s[hi]]) {
                    cnt++;
                }
                hi++;
            }
            if (cnt == (int)t.size() && len > hi - lo) {
                len = hi - lo;
                res = lo;
            }
            if (--win[s[lo]] < tar[s[lo]]) {
                cnt--;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
