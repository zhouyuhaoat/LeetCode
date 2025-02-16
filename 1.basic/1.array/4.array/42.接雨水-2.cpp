/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 21:23:32
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        stack<int> st;
        for (int i = 0; i < (int)height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                // update the result during maintain the (descending) monotonic stack
                // concave area: left, lowest, right
                int top = st.top(); // lowest: first top
                st.pop();
                if (st.empty()) break;
                int w = i - st.top() - 1; // left: second top; right: current
                int h = min(height[i], height[st.top()]) - height[top];
                res += h * w; // row by row
            }
            st.emplace(i);
        }
        return res;
    }
};
// @lc code=end
