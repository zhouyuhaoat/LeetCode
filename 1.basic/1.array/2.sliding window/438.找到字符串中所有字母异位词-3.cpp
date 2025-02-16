/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-13 20:42:22
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // two count -> counteract each other -> one count
        vector<int> cnt(26); // have, need => need - have <=> (-have) + (+need)
        for (char c : p) {
            cnt[c - 'a']++;
        }
        int dif = ranges::count_if(cnt, [](int c) {
            return c != 0; // non-same -> non-zero
        });
        vector<int> res;
        for (int i = 0; i < (int)s.size(); i++) {
            int& r = cnt[s[i] - 'a'];
            if (r == 1) { // non-zero -> zero
                dif--;
            } else if (r == 0) { // zero -> non-zero
                dif++;
            }
            r--;
            if (i >= (int)p.size() - 1) {
                if (dif == 0) {
                    res.emplace_back(i - p.size() + 1);
                }
                int& l = cnt[s[i - p.size() + 1] - 'a'];
                if (l == -1) { // non-zero -> zero
                    dif--;
                } else if (l == 0) { // zero -> non-zero
                    dif++;
                }
                l++;
            }
        }
        return res;
    }
};
// @lc code=end
