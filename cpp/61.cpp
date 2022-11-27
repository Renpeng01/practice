#include <iostream>

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
    int cnt = 0;
    ListNode *p = head;
    while (p != nullptr) {
      p = p->next;
      ++cnt;
    }

    if (k > cnt) {
      k = k - cnt;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    while (k > 0) {
      fast = fast->next;
      --k;
    }

    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    ListNode *t = slow->next;

    ListNode *node1 = reverse(head, slow);

    // log start
    ListNode *temp = node1;
    std::cout << "node1" << std::endl;
    while (temp != nullptr) {
      std::cout << temp->val << std::endl;
      temp = temp->next;
    }
    // log end

    ListNode *node2 = reverse(t, fast);

    // log start
    temp = node2;
    std::cout << "node2" << std::endl;
    while (temp != nullptr) {
      std::cout << temp->val << std::endl;
      temp = temp->next;
    }
    // log end

    ListNode *newHead = node2;

    while (node2->next != nullptr) {
      node2 = node2->next;
    }

    node2->next = node1;

    return newHead;
  }

  ListNode *reverse(ListNode *beginNode, ListNode *endNode) {

    if (beginNode == endNode) {
      return beginNode;
    }

    ListNode *currnet = beginNode;
    ListNode *next = currnet->next;
    currnet->next = nullptr;
    ListNode *temp = nullptr;

    while (next != endNode) {
      temp = next;
      next = next->next;
      temp->next = currnet;
      currnet = temp;
      std::cout << "555555" << std::endl;
    }
    // temp->next = currnet;
    next->next = currnet;
    return next;
  }
};

int main() {
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  ListNode *originListNode = node1;
  std::cout << "origin list node" << std::endl;
  while (originListNode != nullptr) {
    std::cout << originListNode->val << std::endl;
    originListNode = originListNode->next;
  }

  Solution *solution = new Solution();

  ListNode *node = solution->rotateRight(node1, 2);

  std::cout << "merge result" << std::endl;
  while (node != nullptr) {
    std::cout << node->val << std::endl;
    node = node->next;
  }

  return 0;
}