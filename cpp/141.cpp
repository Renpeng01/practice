#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = nullptr;

    if (head == nullptr || head->next == nullptr ||
        head->next->next == nullptr) {
      return false;
    }

    fast = head->next->next;

    while (true) {
      if (slow == fast) {
        return true;
      }

      if (slow->next != nullptr && fast->next != nullptr &&
          fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
      } else {

        return false;
      }
    }
    return false;
  }
};

int main() {
  ListNode *node1 = new ListNode(3);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(0);
  ListNode *node4 = new ListNode(-4);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node2;

  Solution *solution = new Solution();

  bool isCycle = solution->hasCycle(node1);

  if (isCycle) {
    std::cout << "is cycle" << std::endl;
  } else {
    std::cout << "is not cycle" << std::endl;
  }
}
