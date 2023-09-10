// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
  ListNode *reverseKGroup(ListNode *head, int k) {
    std::vector<ListNode *> listVec;
    while (head) {
      listVec.push_back(head);
      head = head->next;
    }

    for (int i = 0; (i + k - 1) < listVec.size(); i += k) {
      int start = i;
      int end = i + k - 1;
      while (start < end) {
        ListNode *temp = listVec[start];
        listVec[start] = listVec[end];
        listVec[end] = temp;
        start++;
        end--;
      }
    }

    for (int i = 0; i < listVec.size() - 1; i++) {
      listVec[i]->next = listVec[i + 1];
    }
    listVec[listVec.size() - 1]->next = nullptr;

    return listVec[0];
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
  ListNode *head = CreateLinkedListFromArray({1, 2, 3, 4, 5, 6});
  int k = 2;
  PrintLinkedList(head); // 1 2 3 4 5
  head = s.reverseKGroup(head, k);
  PrintLinkedList(head); // 3 2 1 4 5

  return 0;
}