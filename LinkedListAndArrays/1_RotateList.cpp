// https://leetcode.com/problems/rotate-list/description/

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
      return head;
    }

    ListNode *temp = head;
    int len = 1;
    while (temp->next) {
      len++;
      temp = temp->next;
    }

    temp->next = head;
    k = (k % len);
    int end = len - k;
    while (end--) {
      temp = temp->next;
    }

    head = temp->next;
    temp->next = nullptr;

    return head;
  }
};