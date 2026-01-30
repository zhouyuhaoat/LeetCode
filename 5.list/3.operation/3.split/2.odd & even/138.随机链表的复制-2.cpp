/*
 *   author:    zhouyuhao
 *   created:   2025-12-23 21:56:53
 *   modified:  2026-01-22 15:01:50
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
class Solution {
private:
    struct List {
        Node *head, *tail;
    };

    pair<List, List> splitByOddEven(Node *head) {
        Node *oddHead = head, *evenHead = head->next;
        Node *odd = oddHead, *even = evenHead;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = nullptr;
        return {{oddHead, odd}, {evenHead, even}};
    }

public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;

        for (Node *curr = head; curr; curr = curr->next->next) {
            curr->next = new Node(curr->val, curr->next, nullptr);
        }

        for (Node *curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        auto [origList, copyList] = splitByOddEven(head);
        return copyList.head;
    }
};
// @lc code=end
