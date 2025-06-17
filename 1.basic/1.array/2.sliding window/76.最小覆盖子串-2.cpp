/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:51:00
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
        for (char ch : t) {
            tar[ch]++;
        }
        int res = -1, len = INT_MAX;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            if (tar.contains(s[hi])) {
                win[s[hi]]++;
            }
            while (cover()) {
                if (hi - lo + 1 < len) {
                    len = hi - lo + 1;
                    res = lo;
                }
                if (tar.contains(s[lo])) {
                    win[s[lo]]--;
                }
                lo++;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
