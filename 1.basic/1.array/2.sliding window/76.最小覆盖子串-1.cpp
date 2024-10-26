/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 13:09:30
 * 	 modified: 	2024-10-26 13:19:51
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
    unordered_map<char, int> win, tar;
    bool cover() {
        for (auto it : tar) {
            if (win[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        for (char c : t) {
            tar[c]++;
        }
        int res = -1, len = INT_MAX;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) {
            if (tar.find(s[hi]) != tar.end()) {
                win[s[hi]]++;
            }
            while (cover()) {
                if (hi - lo + 1 < len) {
                    len = hi - lo + 1;
                    res = lo;
                }
                if (tar.find(s[lo]) != tar.end()) {
                    win[s[lo]]--;
                }
                lo++;
            }
            while (lo <= hi && tar.find(s[lo]) == tar.end()) {
                lo++;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
