#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>>reverseList(shared_ptr<ListNode<int>>L){
  shared_ptr<ListNode<int>>current = L;
  shared_ptr<ListNode<int>>prev = nullptr;
  shared_ptr<ListNode<int>>next = nullptr;

  while(current){
    next = current->next;
    current->next = prev;
    prev = current;
    current= next;
  }
  return prev;
}
bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L) {
  shared_ptr<ListNode<int>>slow_iter = L;
  shared_ptr<ListNode<int>>fast_iter = L;

  while(fast_iter && fast_iter->next){
    slow_iter = slow_iter->next;
    fast_iter = fast_iter->next->next;
  }
  shared_ptr<ListNode<int>> secondHalf = reverseList(slow_iter);
  // slow_iter->next = nullptr;
  shared_ptr<ListNode<int>>firstHalf = L;

  while(firstHalf && secondHalf){
    if(firstHalf->data != secondHalf->data){
      return false;
    }
    firstHalf = firstHalf->next;
    secondHalf= secondHalf->next;
  }
  // TODO - you fill in here.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "is_list_palindromic.cc",
                         "is_list_palindromic.tsv", &IsLinkedListAPalindrome,
                         DefaultComparator{}, param_names);
}
