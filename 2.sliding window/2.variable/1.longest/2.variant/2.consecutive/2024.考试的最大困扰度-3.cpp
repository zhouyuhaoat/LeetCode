/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:52:36
 *   modified:  2025-12-28 09:27:10
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0;
        unordered_map<char, int> cnt;
        for (int lo = 0, hi = 0; hi < (int)answerKey.size(); hi++) { // [lo, hi]
            cnt[answerKey[hi]]++;
            while (cnt['T'] > k && cnt['F'] > k) { // both
                cnt[answerKey[lo++]]--;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
// @lc code=end
