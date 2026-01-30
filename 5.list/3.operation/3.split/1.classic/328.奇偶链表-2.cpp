/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:37:33
 *   modified:  2026-01-22 14:21:30
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
class Solution {
private:
    struct List {
        ListNode *head, *tail;
    };

    pair<List, List> splitByIndex(ListNode *head) {
        ListNode dummy1, dummy2, *odd = &dummy1, *even = &dummy2;
        int idx = 0;
        while (head) {
            if (++idx % 2 == 1) {
                odd = odd->next = head;
            } else {
                even = even->next = head;
            }
            head = head->next;
        }
        odd->next = nullptr, even->next = nullptr; // cut
        return {{dummy1.next, odd}, {dummy2.next, even}};
    }

public:
    ListNode *oddEvenList(ListNode *head) {
        auto [odd, even] = splitByIndex(head);
        if (odd.head) {
            odd.tail->next = even.head; // connect
            return odd.head;
        } else {
            return even.head;
        }
    }
};
// @lc code=end
