/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 10:04:37
 *   modified:  2025-12-25 11:49:58
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = ranges::upper_bound(letters, target);
        return it == letters.end() ? letters[0] : *it;
    }
};
// @lc code=end
