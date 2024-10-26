/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-25 20:40:40
 * 	 modified: 	2024-10-25 21:02:42
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
            cnt[c - 'a']++; // +1
        }
        int dif = 0; // difference for fast judge
        for (int it : cnt) { // dif != p.size()
            if (it != 0) {
                dif++;
            }
        }
        vector<int> res;
        for (int i = 0; i < (int)s.size(); i++) {
            int& r = cnt[s[i] - 'a'];
            if (r == 1) { // 1 -> 0
                dif--;
            } else if (r == 0) { // 0 -> -1
                dif++;
            }
            r--;
            if (i >= (int)p.size() - 1) {
                if (dif == 0) {
                    res.emplace_back(i - p.size() + 1);
                }
                int& l = cnt[s[i - p.size() + 1] - 'a'];
                if (l == -1) { // -1 -> 0
                    dif--;
                } else if (l == 0) { // 0 -> 1
                    dif++;
                }
                l++;
            }
        }
        return res;
    }
};
// @lc code=end
