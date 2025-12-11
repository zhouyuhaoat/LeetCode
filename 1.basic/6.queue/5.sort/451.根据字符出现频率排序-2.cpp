/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 20:49:35
 *   modified:  2025-12-04 09:36:53
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char ch : s) {
            cnt[ch]++;
        }
        ranges::sort(s, [&](char& a, char& b) {
            return cnt[a] != cnt[b] ? cnt[a] > cnt[b] : a < b;
        });
        return s;
    }
};
// @lc code=end
