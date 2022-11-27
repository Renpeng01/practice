#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = nullptr;

    if (head == nullptr || head->next == nullptr ||
        head->next->next == nullptr) {
      return nullptr;
    }

    fast = head->next->next;
    // TODO: 这里容易遗漏 初始化时只给fast移动 忘记给slow移动
    slow = slow->next;

    while (true) {
      if (slow == fast) {
        break;
      }

      if (slow->next != nullptr && fast->next != nullptr &&
          fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
      } else {
        return nullptr;
      }
    }

    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
      // std::cout << "1111" << std::endl;
    }

    return slow;
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

  ListNode *node = solution->detectCycle(node1);

  std::cout << node->val << std::endl;
}
