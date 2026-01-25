/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 10:04:37
 *   modified:  2026-01-23 13:31:20
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
        return letters[(ranges::upper_bound(letters, target) - letters.begin()) % (int)letters.size()];
    }
};
// @lc code=end
