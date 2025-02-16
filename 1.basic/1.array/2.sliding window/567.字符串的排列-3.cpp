/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-12 23:34:41
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
        int dif = ranges::count_if(cnt, [](int c) {
            return c != 0;
        });
        for (int i = 0; i < (int)s2.size(); i++) {
            int& r = cnt[s2[i] - 'a'];
            if (r == 1) {
                dif--;
            } else if (r == 0) {
                dif++;
            }
            r--;
            if (i >= (int)s1.size() - 1) {
                if (dif == 0) return true;
                int& l = cnt[s2[i - s1.size() + 1] - 'a'];
                if (l == -1) {
                    dif--;
                } else if (l == 0) {
                    dif++;
                }
                l++;
            }
        }
        return false;
    }
};
// @lc code=end
