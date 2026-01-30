/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 18:40:19
 *   modified:  2026-01-17 21:29:58
 *   project:   LeetCode
 *   venue:     A20, Harbin
 */

/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 *
 * [3217] 从链表中移除在数组中存在的节点
 */

// @lc code=start
class Solution {
public:
    ListNode *modifiedList(vector<int>& nums, ListNode *head) {
        ListNode dummy(0, head), *pred = &dummy;
        unordered_set<int> vals(nums.begin(), nums.end());
        while (pred->next) {
            ListNode *curr = pred->next;
            if (vals.contains(curr->val)) {
                pred->next = curr->next;
                // delete curr;
            } else {
                pred = curr;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
