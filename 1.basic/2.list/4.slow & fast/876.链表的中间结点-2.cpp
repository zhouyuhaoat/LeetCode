/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-27 18:40:42
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
class Solution {
public:
    int getSize(ListNode *head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode *middleNode(ListNode *head) {
        int id = getSize(head) / 2;
        ListNode *middle = head;
        while (id--) {
            middle = middle->next;
        }
        return middle;
    }
};
// @lc code=end
