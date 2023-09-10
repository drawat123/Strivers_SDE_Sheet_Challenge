// https://leetcode.com/problems/palindrome-linked-list/

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
  bool isPalindrome(ListNode *head) {
    ListNode *middleNode = head, *fast = head;
    while (fast && fast->next) {
      middleNode = middleNode->next;
      fast = fast->next->next;
    }

    ListNode *curr = middleNode, *prev = nullptr;
    while (curr) {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }

    ListNode *lastNode = prev;
    while (head != middleNode) {
      if (head->val != lastNode->val) {
        return false;
      }
      head = head->next;
      lastNode = lastNode->next;
    }

    return true;
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
  ListNode *head = CreateLinkedListFromArray({1, 2, 1});
  Solution s;
  std::cout << s.isPalindrome(head);

  return 0;
}