/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:50:49
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
private:
    unordered_map<char, int> win, tar; // have & need

    bool isCovered() { // cover: have >= need
        for (auto [ch, cnt] : tar) {
            if (win[ch] < cnt) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        for (char ch : t) {
            tar[ch]++;
        }
        int res = -1, len = INT_MAX;
        for (int lo = 0, hi = 0; lo < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && !isCovered()) {
                if (tar.contains(s[hi])) {
                    win[s[hi]]++;
                }
                hi++;
            }
            if (isCovered() && hi - lo < len) {
                len = hi - lo;
                res = lo;
            }
            if (tar.contains(s[lo])) {
                win[s[lo]]--;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
