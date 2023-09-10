// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int numOfNodes = 0;
    ListNode *temp = head, *slow = nullptr, *fast = head;
    while (temp) {
      numOfNodes++;
      temp = temp->next;
    }

    n = numOfNodes - n + 1;
    while (n - 1 > 0) {
      slow = fast;
      fast = fast->next;
      n--;
    }

    if (slow) {
      slow->next = fast->next;
      delete fast;
    } else {
      temp = head;
      head = head->next;
      delete temp;
    }

    return head;
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

  ListNode *head = CreateLinkedListFromArray({1, 2, 3, 4, 5});
  PrintLinkedList(head);
  head = s.removeNthFromEnd(head, 1);
  PrintLinkedList(head);

  return 0;
}