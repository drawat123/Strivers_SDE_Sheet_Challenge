// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  int data;
  struct Node *next;
  struct Node *bottom;

  Node(int x) {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

Node *MergeTwoLists(Node *l1, Node *l2) {
  Node *res = new Node(0), *temp = res;

  while (l1 && l2) {
    if (l1->data < l2->data) {
      temp->bottom = l1;
      temp = temp->bottom;
      l1 = l1->bottom;
    } else {
      temp->bottom = l2;
      temp = temp->bottom;
      l2 = l2->bottom;
    }
  }

  if (l1) {
    temp->bottom = l1;
  } else {
    temp->bottom = l2;
  }

  temp = res;
  res = res->bottom;
  delete temp;

  return res;
}

Node *flatten(Node *root) {
  if (!root || !root->next) {
    return root;
  }

  root->next = flatten(root->next);

  root = MergeTwoLists(root, root->next);

  return root;
}