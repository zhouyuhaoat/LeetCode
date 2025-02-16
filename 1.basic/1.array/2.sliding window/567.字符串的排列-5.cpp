/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-16 10:18:44
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26);
        for (char c : s1) {
            cnt[c - 'a']++;
        }
        int want = s1.size();
        for (int lo = 0, hi = 0; lo <= (int)s2.size() - (int)s1.size(); lo++) {
            while (hi < (int)s2.size() && want > 0) {
                if (cnt[s2[hi++] - 'a']-- > 0) {
                    want--;
                }
            }
            if (want == 0 && hi - lo == (int)s1.size()) {
                return true;
            }
            if (++cnt[s2[lo] - 'a'] > 0) {
                want++;
            }
        }
        return false;
    }
};
// @lc code=end
