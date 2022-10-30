/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int n = 0;
        auto cur = head;
        while (cur->next) {
            n++;
            cur = cur->next;
        }
        n++;
        k %= n;
        if (k == 0) return head;
        auto tail = cur;
        tail->next = head;
        int m = n - k;
        cur = head;
        for (int i = 0; i < m - 1; i++) {
            cur = cur->next;
        }
        auto ret = cur->next;
        cur->next = nullptr;
        return ret;
    }
};