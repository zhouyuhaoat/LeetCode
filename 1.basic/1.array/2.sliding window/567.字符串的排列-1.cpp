/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-12 23:33:59
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
        for (int i = 0; i < (int)s2.size(); i++) {
            cnt2[s2[i] - 'a']++;
            if (i >= (int)s1.size() - 1) {
                if (cnt1 == cnt2) return true;
                cnt2[s2[i - s1.size() + 1] - 'a']--;
            }
        }
        return false;
    }
};
// @lc code=end
