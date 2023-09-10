// https://leetcode.com/problems/add-two-numbers/
#include <iostream>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    ListNode *newList = new ListNode(), *tempNode = newList;
    int nodeVal = 0, carry = 0;
    while (l1 && l2) {
      int sum = carry + l1->val + l2->val;
      nodeVal = sum % 10;
      carry = sum / 10;
      tempNode->next = new ListNode(nodeVal);
      l1 = l1->next;
      l2 = l2->next;
      tempNode = tempNode->next;
    }

    while (l1) {
      int sum = carry + l1->val;
      nodeVal = sum % 10;
      carry = sum / 10;
      tempNode->next = new ListNode(nodeVal);
      l1 = l1->next;
      tempNode = tempNode->next;
    }

    while (l2) {
      int sum = carry + l2->val;
      nodeVal = sum % 10;
      carry = sum / 10;
      tempNode->next = new ListNode(nodeVal);
      l2 = l2->next;
      tempNode = tempNode->next;
    }

    if (carry) {
      tempNode->next = new ListNode(carry);
      tempNode = tempNode->next;
    }

    tempNode = newList;
    newList = newList->next;
    delete tempNode;

    return newList;
  }
};

ListNode *CreateLinkedListFromArray(std::vector<int> vec) {
  if (vec.size() == 0)
    return nullptr;

  ListNode *head = new ListNode(vec[0]), *temp = head;
  for (int i = 1; i < vec.size(); i++) {
    temp->next = new ListNode(vec[i]);
    temp = temp->next;
  }

  return head;
}

void PrintLinkedList(ListNode *head) {
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << '\n';
}

int main() {
  Solution s;

  ListNode *head1 = CreateLinkedListFromArray({9, 9, 9, 9, 9, 9, 9}),
           *head2 = CreateLinkedListFromArray({9, 9, 9, 9});
  PrintLinkedList(head1);
  PrintLinkedList(head2);
  head1 = s.addTwoNumbers(head1, head2);
  PrintLinkedList(head1);

  return 0;
}

/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/