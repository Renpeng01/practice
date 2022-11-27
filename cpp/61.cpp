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
    if (head == nullptr || k == 0) {
      return head;
    }

    ListNode *end = head;
    int cnt = 0;

    while (end->next != nullptr) {
      end = end->next;
      ++cnt;
    }
    ++cnt;

    if (cnt == 1) {
      return head;
    }

    head = reverse(head, end);

    if (k > cnt) {
      k = k % cnt;
    }
    k = (cnt - k) % cnt;

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

    ListNode *node2 = reverse(t, fast);
    ListNode *newHead = node1;

    while (node1->next != nullptr) {
      node1 = node1->next;
    }

    node1->next = node2;
    return newHead;
  }

  ListNode *reverse(ListNode *beginNode, ListNode *endNode) {

    if (beginNode == nullptr || endNode == nullptr) {
      return nullptr;
    }

    if (beginNode == endNode) {
      beginNode->next = nullptr;
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
    }
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

  // ListNode *node1 = new ListNode(1);
  // ListNode *node2 = new ListNode(2);
  // ListNode *node3 = new ListNode(3);

  // node1->next = node2;
  // node2->next = node3;

  // ListNode *node1 = new ListNode(1);

  ListNode *originListNode = node1;
  std::cout << "origin list node" << std::endl;
  while (originListNode != nullptr) {
    std::cout << originListNode->val << std::endl;
    originListNode = originListNode->next;
  }

  Solution *solution = new Solution();

  ListNode *node = solution->rotateRight(node1, 10);

  std::cout << "merge result" << std::endl;
  while (node != nullptr) {
    std::cout << node->val << std::endl;
    node = node->next;
  }

  return 0;
}