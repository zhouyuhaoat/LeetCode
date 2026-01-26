/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:52:20
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
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
        vector<int> res, cnt(128);
        for (char ch : p) {
            cnt[ch]++;
        }
        /*
            two count -> counteract each other -> one count
            - count = need - have = (-have) + (+need)
            - different => !zero; same => zero
         */
        int diff = ranges::count_if(cnt, [](int val) {
            return val != 0;
        });
        for (int hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            int& right = cnt[s[hi]];
            if (right == 0) {
                diff++;
            } else if (right == 1) {
                diff--;
            }
            right--;
            int lo = hi - p.size() + 1;
            if (lo >= 0) {
                if (diff == 0) {
                    res.push_back(lo);
                }
                int& left = cnt[s[lo]];
                if (left == 0) {
                    diff++;
                } else if (left == -1) {
                    diff--;
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end
