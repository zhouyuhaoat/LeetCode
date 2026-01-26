/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:16:43
 *   modified:  2025-05-22 18:52:07
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
        vector<int> res, cnt1(128), cnt2(128);
        for (char ch : p) {
            cnt2[ch]++;
        }
        /*
            diff: count difference between strings
            - anagram: have = need => diff = 0
         */
        int diff = ranges::count_if(cnt2, [&, i = 0](int val) mutable {
            return cnt2[i] != cnt1[i++];
        });
        for (int hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            int& right = cnt1[s[hi]];
            if (right == cnt2[s[hi]]) { // same -> different
                diff++;
            } else if (right == cnt2[s[hi]] - 1) { // different -> same
                diff--;
            }
            right++;
            int lo = hi - p.size() + 1;
            if (lo >= 0) {
                if (diff == 0) {
                    res.push_back(lo);
                }
                int& left = cnt1[s[lo]];
                if (left == cnt2[s[lo]]) { // same -> different
                    diff++;
                } else if (left == cnt2[s[lo]] + 1) { // different -> same
                    diff--;
                }
                left--;
            }
        }
        return res;
    }
};
// @lc code=end
