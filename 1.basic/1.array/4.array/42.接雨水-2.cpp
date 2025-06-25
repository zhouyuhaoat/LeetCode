/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-21 22:08:11
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stk; // (descending) monotonic stack
        for (int i = 0; i < (int)height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                /*
                    concave area
                    1. left: second top
                    2. lowest: first top
                    3. right: current
                */
                int low = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top(), right = i;
                int h = min(height[left], height[right]) - height[low], w = right - left - 1;
                res += h * w; // row by row
            }
            stk.emplace(i);
        }
        return res;
    }
};
// @lc code=end
