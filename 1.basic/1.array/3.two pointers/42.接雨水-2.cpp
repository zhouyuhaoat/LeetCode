/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 18:45:23
 * 	 modified: 	2024-10-26 18:54:21
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        stack<int> st; // monotonic stack: descending
        for (int i = 0; i < (int)height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                // concave area: left, lowest, right
                int top = st.top(); // first top: lowest
                st.pop();
                if (st.empty()) break; // second top: left
                int w = i - st.top() - 1; // current: right
                int h = min(height[i], height[st.top()]) - height[top];
                res += h * w; // row by row
            }
            st.emplace(i);
        }
        return res;
    }
};
// @lc code=end
