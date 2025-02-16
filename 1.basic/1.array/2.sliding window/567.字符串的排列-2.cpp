/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:35:12
 * 	 modified: 	2025-02-12 23:36:47
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
        vector<int> cnt1(26), cnt2(26);
        for (char c : s1) {
            cnt1[c - 'a']++;
        }
        int dif = ranges::count_if(cnt1, [&cnt1, &cnt2, i = 0](int val) mutable {
            return cnt1[i] != cnt2[i++];
        });
        for (int i = 0; i < (int)s2.size(); i++) {
            int& r = cnt2[s2[i] - 'a'];
            if (r == cnt1[s2[i] - 'a']) {
                dif++;
            } else if (r == cnt1[s2[i] - 'a'] - 1) {
                dif--;
            }
            r++;
            if (i >= (int)s1.size() - 1) {
                if (dif == 0) return true;
                int& l = cnt2[s2[i - s1.size() + 1] - 'a'];
                if (l == cnt1[s2[i - s1.size() + 1] - 'a']) {
                    dif++;
                } else if (l == cnt1[s2[i - s1.size() + 1] - 'a'] + 1) {
                    dif--;
                }
                l--;
            }
        }
        return false;
    }
};
// @lc code=end
