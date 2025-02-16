/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-12 23:39:05
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
        int dif = cnt.size() - ranges::count(cnt, 0);
        auto update = [&](int idx, int add) {
            if (cnt[idx] == 0) dif++;
            cnt[idx] += add;
            if (cnt[idx] == 0) dif--;
        };
        for (int i = 0; i < (int)s2.size(); i++) {
            update(s2[i] - 'a', -1);
            if (i >= (int)s1.size() - 1) {
                if (dif == 0) return true;
                update(s2[i - s1.size() + 1] - 'a', 1);
            }
        }
        return false;
    }
};
// @lc code=end
