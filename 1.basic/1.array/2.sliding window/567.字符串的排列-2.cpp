/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-25 21:08:29
 * 	 modified: 	2024-10-25 21:13:02
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        int dif = 0;
        for (int it : cnt) {
            if (it != 0) {
                dif++;
            }
        }
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
