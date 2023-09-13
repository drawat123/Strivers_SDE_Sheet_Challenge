// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <iostream>
#include <unordered_map>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    std::unordered_map<Node *, Node *> nodeMap{{NULL, NULL}};
    Node *oldList = head;

    while (oldList) {
      Node *temp = new Node(oldList->val);
      nodeMap[oldList] = temp;
      oldList = oldList->next;
    }

    oldList = head;
    while (oldList) {
      Node *newNode = nodeMap[oldList];
      newNode->next = nodeMap[oldList->next];
      newNode->random = nodeMap[oldList->random];
      oldList = oldList->next;
    }

    return nodeMap[head];
  }
};