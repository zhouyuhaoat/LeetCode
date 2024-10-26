/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 13:30:52
 * 	 modified: 	2024-10-26 13:35:39
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        unordered_map<char, int> tar;
        for (char c : t) {
            tar[c]++;
        }
        int cnt = 0, res = -1, len = INT_MAX;
        unordered_map<char, int> win;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) {
            if (++win[s[hi]] <= tar[s[hi]]) {
                cnt++;
            }
            while (cnt >= (int)t.size()) {
                if (hi - lo + 1 < len) {
                    len = hi - lo + 1;
                    res = lo;
                }
                if (win[s[lo]]-- <= tar[s[lo]]) {
                    cnt--;
                }
                lo++;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
