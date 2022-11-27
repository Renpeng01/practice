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
  bool isPalindrome2(ListNode *head) {
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

  bool isPalindrome3(ListNode *head) {
    int cnt = 0;
    ListNode *p = head;

    while (p != nullptr) {
      ++cnt;
      p = p->next;
    }

    bool isOdd = (cnt % 2 == 1);

    std::stack<int> mStack;
    int cntNew = 0;

    while (cntNew < cnt / 2) {
      mStack.push(head->val);
      ++cntNew;
      head = head->next;
    }

    if (isOdd) {
      head = head->next;
    }

    while (head != nullptr) {
      if (mStack.top() != head->val) {
        return false;
      }

      mStack.pop();
      head = head->next;
    }

    return true;
  }

  //  使用vector 代替stack 内内存占用并没有提升反而略微下降
  bool isPalindrome(ListNode *head) {
    int cnt = 0;
    ListNode *p = head;

    while (p != nullptr) {
      ++cnt;
      p = p->next;
    }

    bool isOdd = (cnt % 2 == 1);

    std::vector<int> vec;
    vec.reserve(cnt / 2);
    int cntNew = 0;

    while (cntNew < cnt / 2) {
      vec.push_back(head->val);
      ++cntNew;
      head = head->next;
    }

    if (isOdd) {
      head = head->next;
    }

    while (head != nullptr) {
      if (vec.back() != head->val) {
        return false;
      }

      vec.pop_back();
      head = head->next;
    }

    return true;
  }
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