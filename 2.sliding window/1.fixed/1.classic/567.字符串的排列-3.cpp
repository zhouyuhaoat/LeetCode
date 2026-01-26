/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:53:50
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
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
        vector<int> cnt(128);
        for (char ch : s1) {
            cnt[ch]++;
        }
        int diff = ranges::count_if(cnt, [](int val) {
            return val != 0;
        });
        for (int hi = 0; hi < (int)s2.size(); hi++) {
            int& right = cnt[s2[hi]];
            if (right == 0) {
                diff++;
            } else if (right == 1) {
                diff--;
            }
            right--;
            int lo = hi - s1.size() + 1;
            if (lo >= 0) {
                if (diff == 0) {
                    return true;
                }
                int& left = cnt[s2[lo]];
                if (left == 0) {
                    diff++;
                } else if (left == -1) {
                    diff--;
                }
                left++;
            }
        }
        return false;
    }
};
// @lc code=end
