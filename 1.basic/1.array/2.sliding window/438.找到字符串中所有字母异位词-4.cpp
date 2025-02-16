/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-12 23:30:29
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
        vector<int> cnt(26);
        for (char c : p) {
            cnt[c - 'a']++;
        }
        int dif = cnt.size() - ranges::count(cnt, 0);
        vector<int> res;
        auto update = [&](int idx, int add) {
            if (cnt[idx] == 0) dif++; // same before update -> different after update
            cnt[idx] += add;
            if (cnt[idx] == 0) dif--; // same after update
        };
        for (int i = 0; i < (int)s.size(); i++) {
            update(s[i] - 'a', -1);
            if (i >= (int)p.size() - 1) {
                if (dif == 0) {
                    res.emplace_back(i - p.size() + 1);
                }
                update(s[i - p.size() + 1] - 'a', 1);
            }
        }
        return res;
    }
};
// @lc code=end
