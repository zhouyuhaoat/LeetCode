/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:37:33
 *   modified:  2026-01-22 14:40:02
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

    pair<List, List> splitByOddEven(ListNode *head) {
        ListNode *oddHead = head, *evenHead = head->next;
        ListNode *odd = oddHead, *even = evenHead;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = nullptr; // cut
        return {{oddHead, odd}, {evenHead, even}};
    }

public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return nullptr;
        auto [odd, even] = splitByOddEven(head);
        if (odd.head) {
            odd.tail->next = even.head; // connect
            return odd.head;
        } else {
            return even.head;
        }
    }
};
// @lc code=end
