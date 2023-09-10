// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
  int LengthOfList(ListNode *head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }

public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = LengthOfList(headA), lenB = LengthOfList(headB);
    int diff = std::abs(lenA - lenB);

    if (lenA > lenB) {
      while (diff--) {
        headA = headA->next;
      }
    } else if (lenB > lenA) {
      while (diff--) {
        headB = headB->next;
      }
    }

    while (headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }

    return headA;
  }
};