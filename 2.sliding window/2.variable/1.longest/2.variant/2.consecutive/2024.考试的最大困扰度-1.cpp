/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:52:36
 *   modified:  2025-12-28 09:19:07
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
private:
    int maxConsecutiveChar(string& s, int k, char ch) {
        int res = 0, cnt = 0;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            cnt += s[hi] != ch;
            while (cnt > k) {
                cnt -= s[lo++] != ch;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'), maxConsecutiveChar(answerKey, k, 'F'));
    }
};
// @lc code=end
