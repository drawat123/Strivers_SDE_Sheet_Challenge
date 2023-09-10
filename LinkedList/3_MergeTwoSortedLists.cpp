// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *newList = new ListNode(), *tempNode = newList;
    while (list1 && list2) {
      if (list1->val <= list2->val) {
        tempNode->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        tempNode->next = new ListNode(list2->val);
        list2 = list2->next;
      }
      tempNode = tempNode->next;
    }

    while (list1) {
      tempNode->next = new ListNode(list1->val);
      tempNode = tempNode->next;
      list1 = list1->next;
    }

    while (list2) {
      tempNode->next = new ListNode(list2->val);
      tempNode = tempNode->next;
      list2 = list2->next;
    }

    tempNode = newList;
    newList = newList->next;
    delete tempNode;

    return newList;
  }
};