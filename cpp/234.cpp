#include <iostream>
#include <stack>
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
    std::vector<int> vec;
    while (head != nullptr) {
      vec.push_back(head->val);
      head = head->next;
    }

    int headIndex = 0;
    int tailIndex = vec.size() - 1;

    while (headIndex < tailIndex) {
      if (vec.at(headIndex) != vec.at(tailIndex)) {
        return false;
      }
      ++headIndex;
      --tailIndex;
    }

    return true;
  }

  bool isPalindrome2(ListNode *head) {}
};

int main() {
  ListNode *node = new ListNode(1);

  Solution *s = new Solution();
  bool result = s->isPalindrome(node);

  if (result) {
    std::cout << "is palindrome" << std::endl;
  } else {

    std::cout << "is not Palindrome" << std::endl;
  }
}