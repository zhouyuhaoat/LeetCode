/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:14:16
 *   modified:  2025-03-01 20:33:28
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
        priority_queue<pair<int, char>> pq;
        for (auto it : cnt) {
            pq.emplace(it.second, it.first); // {freq, char}
        }
        string res;
        while (!pq.empty()) {
            res += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
