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
class Solution
{
public:
  void reorderList(ListNode *head)
  {
    if (!head->next) return;
    deque<ListNode *> deq;
    ListNode *cur = head;
    while (cur) {
      deq.push_back(cur);
      cur = cur->next;
    }
    while (deq.size() && deq.front() != deq.back()) {
      deq.front()->next = deq.back();
      deq.pop_front();
      deq.back()->next = deq.front();
      cur = deq.front();
      deq.pop_back();
    }
    cur->next = nullptr;
  }
};